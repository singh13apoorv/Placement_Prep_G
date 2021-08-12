template<typename T>

class Stack{
    T *data;
    int nextIdx;
    int capacity;

    public:
    Stack(){
        data = new T[5];
        nextIdx = 0;
        capacity = 5;
    }

    int size(){
        return nextIdx;
    }

    bool isEmpty(){
        if (nextIdx == 0){
            return true;
        }
        return false;
    }

    void push(T element){
        if (nextIdx == capacity){
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }

        data[nextIdx] = element;
        nextIdx++;
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack is empty." << endl;
            return;
        }

        nextIdx--;
        cout << data[nextIdx] << endl;
    }

    void top(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << data[nextIdx - 1] << endl;
    }
};