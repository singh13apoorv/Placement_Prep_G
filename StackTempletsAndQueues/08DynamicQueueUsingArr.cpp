template <typename T>

class Queue{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:
    Queue(){
        data = new T[5];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = 5;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        if (size == capacity){
            T *newData = new T[2 * capacity];
            int j = 0;

            for (int i = firstIndex; i < capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
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