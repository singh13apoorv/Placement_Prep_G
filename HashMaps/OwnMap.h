#include <string>
using namespace std;

template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value){
        this -> key = key;
        this -> value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template <typename V>
class OwnMap{
    MapNode<V>** buckets;
    int NumOfElements;
    int bucketSize;

    public:
    OwnMap() {
        NumOfElements = 0;
        bucketSize = 5;
        buckets = new MapNode<V>*[bucketSize];

        for (int i = 0; i < bucketSize; i++){
            buckets[i] = NULL;
        }
    }

    ~OwnMap(){
        for (int i = 0; i < bucketSize; i++){
            delete buckets[i];
        }

        delete [] buckets;
    }

    int size(){
        return NumOfElements;
    }

    private:
    int getHash(string key) {
        int hashKey = 0;
        int currentCoeff = 1;

        for (int i = key.size() - 1; i >= 0; i--){
            hashKey += (key[i] * currentCoeff);
            hashKey %= bucketSize;
            currentCoeff *= 37;
            currentCoeff %= bucketSize;
        }

        return hashKey % bucketSize;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[bucketSize * 2];

        for (int i = 0; i < bucketSize * 2; i++){
            buckets[i] = NULL;
        }

        int oldsize = bucketSize;
        bucketSize *= 2;
        NumOfElements = 0;

        for (int i = 0; i < oldsize; i++){
            MapNode<V>* head = temp[i];
            while (head != NULL){
                string key = head -> key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }

        for (int i = 0; i < oldsize; i++){
            delete temp[i];
        }
        delete [] temp;
    }

    public:
    double getLoadFactor(){
        return ((1.0 * NumOfElements)/bucketSize);
    }

    V getValue(string key) {
        int bucketIndex = getHash(key);
        MapNode<int>* head = buckets[bucketIndex];

        while (head != NULL){
            if (head -> key == key){
                return head -> value;
            }
            head = head -> next;
        }

        return 0;
    }

    void insert(string key, V value) {
        int bucketIndex = getHash(key);
        MapNode<V>* head = buckets[bucketIndex];

        while (head != NULL){
            if (head -> key == key){
                head -> value = value;
                return;
            }
            head = head -> next;
        }

        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node -> next = head;
        buckets[bucketIndex] = node;
        NumOfElements++;

        double loadFactor = (1.0 * NumOfElements)/bucketSize;

        if (loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key){
        int bucketIndex = getHash(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;

        while (head != NULL){
            if (head -> key == key){
                if (prev == NULL){
                    buckets[bucketIndex] = head -> next;
                }
                else {
                    prev -> next = head -> next;
                }
                V val = head -> value;
                head -> next = NULL;
                NumOfElements--;
                delete head;
                return val;
            }
            prev = head;
            head = head -> next;
        }

        return 0;
    }
};