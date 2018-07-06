#include <iostream>

using namespace std;

struct node {
    int value;
    node *address = NULL;
};

node *insert(node * head,int value) {
    node* temp = new node;
    temp->value = value;
    temp->address = head;
    return temp;
    
};

node *insert(node *head,int value,int index) {
    node *temp = new node;
    if(index==1) {
        temp->value = value;
        temp->address = head;
        return temp;
    }
    temp = head;
    for(int i=0;i<index-2;i++){
        temp=temp->address;
    }
    node *temp1 = new node;
    temp1->value = value;
    temp1->address = temp->address;
    temp->address = temp1;
    return head;
        
}


node *deleteNode(node *head,int index) {
    node *temp = head;
    if(index ==1) {
        temp=temp->address;
        return temp;
    }
    
    for(int i=0;i<index-2;i++) {
        temp = temp->address;
    }
    node *temp1 = temp->address;
    temp->address = temp1->address;
    delete temp1;
    return head;
}

node *reverse(node *head){
    node *prev,*next;
    node *temp= head;
    prev = NULL;
    while(temp!=NULL){
        next = temp->address;
        temp->address = prev;
        prev=temp;
        temp=next;
    }
    return prev;
    
    
}

void reversePrintRecursion(node *head){
    if(head!=NULL) {
        reversePrintRecursion(head->address);
    } else {
        return;
    }
    cout<<head->value<<endl;
    return;
}

void reverseRecursion(node **head,node *p){
    if(p->address == NULL) {
        *head = p;
        return;
    }
    reverseRecursion(head,p->address);
    node *q = p->address;
    q->address = p;
    p->address=NULL;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    node *head = new node;
    head = NULL;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        head  = insert(head,x);
    }
    
    head = insert(head,99,2);
    head = insert(head,100,1);
     
    head = deleteNode(head,2);
    
     reverseRecursion(&head,head);
    cout<<"reverse Print"<<endl;
    reversePrintRecursion(head);
	node *temp = new node;
	temp = head;
	cout<<"Real order"<<endl;
	while(temp!=NULL) {
	    cout<<temp->value<<endl;
	    temp = temp->address; 
	}
}
