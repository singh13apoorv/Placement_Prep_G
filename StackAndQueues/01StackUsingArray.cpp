#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *data;
    int nextIdx;
    int capacity;

    public:
    Stack(int Tcap){
        data = new int[Tcap];
        nextIdx = 0;
        capacity = Tcap;
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
            cout << "Stack is OverFlowing." << endl;
            return;
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
    Stack s(4);

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