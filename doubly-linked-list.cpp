#include <iostream>

using namespace std;

struct node {
    int value;
    node *next = NULL;
    node *prev = NULL;
};

node *insertatHead(node *head,int data) {
    node *newNode = new node;
    newNode->value = data;
    newNode->next=head;
    head->prev=newNode;
    return newNode;
}

node *insertAtTail(node *tail,int data) {
    node *newNode = new node;
    newNode->value = data;
    newNode->prev = tail;
    tail->next= newNode;
    return newNode;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }
}

int main() {
    node *head = new node;
    node *tail = NULL;
    head = insertatHead(head,5);
    head->next = NULL;
    tail=head;
    head = insertatHead(head,6);
    print(head);
    cout<<endl;
    tail = insertAtTail(tail,7);
    tail = insertAtTail(tail,9);
     head = insertatHead(head,4);
    print(head);
    
}