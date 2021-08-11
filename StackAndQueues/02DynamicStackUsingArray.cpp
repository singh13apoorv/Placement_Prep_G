#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *data;
    int nextIdx;
    int capacity;

    public:
    Stack(){
        data = new int[5];
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

    void push(int element){
        if (nextIdx == capacity){
            int *newData = new int[2 * capacity];
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

int main(){
    Stack s;

    s.pop();
    s.top();
    cout << s.isEmpty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.top();
    s.pop();
    s.top();
    s.push(50);
    s.top();

    return 0;
}