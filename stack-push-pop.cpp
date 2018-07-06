#include <iostream>

using namespace std;

struct node {
    int value;
    node *address = NULL;
};

node *push(node *head,int value){
    node *temp = new node;
    temp->value= value;
    temp->address = head;
    return temp;    
}

node *pop(node *head) {
    node *temp=head;
    head = head->address;
    delete temp;
    return head;
}

void print(node *head) {
    while(head!=NULL) {
        cout<<head->value<<" ";
        head=head->address;
    }
    cout<<endl;
}

int main() {
	node *head=NULL;
	head=push(head,5);
	head=push(head,6);
	head=push(head,7);
	
	print(head);
	
	head= pop(head);
	print(head);

}