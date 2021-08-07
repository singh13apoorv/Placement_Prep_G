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
    string input = "yes";

    while (input == "yes"){
        Node* newNode = new Node(data);
        if (head == NULL){
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cout << "Enter the data: ";
        cin >> data;
        cout << "Enter your decision(yes, no): ";
        cin >> input;
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

    return 0;
}