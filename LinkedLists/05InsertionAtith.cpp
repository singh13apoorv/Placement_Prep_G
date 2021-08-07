#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

Node* TakeInput(){
    int data;
    cout << "Enter first data: ";
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    string input = "yes";

    while (input == "yes"){
        Node* newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        cout << "Enter the data: ";
        cin >> data;
        cout << "Enter your decision(yes, no): ";
        cin >> input;
    }

    return head;
}

Node* InsertAtI(Node* head, int data, int i){
    Node* newNode = new Node(data);
    int count = 0;
    Node* temp = head;

    if (i == 0){
        newNode -> next = head;
        head = newNode;

        return head;
    }

    while(temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }

    if (temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    return head;
}

void print(Node* head){
    Node* temp = head;

    while (temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}


int main(){
    Node* head = TakeInput();
    print(head);
    Node* headn = InsertAtI(head, -10, 7);
    print(headn);

    return 0;
}