#include <iostream>

using namespace std;

struct node {
    int data;
    node *left=NULL;
    node *right=NULL;
};

node *insert(node *root,int value) {
   
    if(root==NULL){
         node *temp = new node;
        temp->data = value;
        return temp;
    } else if(value<=root->data){
        root->left = insert(root->left,value);
    } else {
        root->right = insert(root->right,value);
    }
    return root;
    
}

int findMin(node *root){
    if(root == NULL) {
        cout<<"Error , tree is empty\n";
        return -1;
    }
    while(root->left!=NULL) {
        root= root->left;
    }
    return root->data;
}
int findMax(node *root) {
    if(root==NULL) {
        cout<<"Errot: tree is empty";
        return -1;
    }
    while(root->right!=NULL) {
        root= root->right;
    }
    return root->data;
}

bool search(node *root, int data) {
    if(root==NULL) return false;
    else if(root->data== data) return true;
    else if(root->data> data) return search(root->left,data);
    else return search(root->right,data);
    
}

int max(int a, int b){
    if(a>b) {
        return a;
    }
    return b;
}

int findHeight(node *root) {
    if(root==NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight,rightHeight) +1;
    
}

int main() {
    node *root;
    root =NULL;
    root =insert(root,15);
    root =insert(root,10);
    root =insert(root,20);
    root =insert(root,25);
    root =insert(root,8);
    root =insert(root,12);
    root =insert(root,13);
    cout<<search(root,8)<<endl;
    cout<<search(root,110)<<endl;
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<findHeight(root);
    
}