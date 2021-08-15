template <typename T>

class Queue{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:
    Queue(int s){
        data = new T(s);
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        if (size == capacity){
            cout << "Queue is full!" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T front(){
        if (size == 0){
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if (size == 0){
            cout << "Queue is empty!" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
};