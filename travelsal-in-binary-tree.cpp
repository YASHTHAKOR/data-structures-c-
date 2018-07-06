#include <iostream>
#include<queue>
using namespace std;

struct node {
  int data;
  node *left =NULL;
  node *right = NULL;
};

void preorder(node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postOrder(node *root) {
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}

void inOrder(node *root) {
    if(root==NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data;
}

void levelOrder( node * root) {
    it(root == NULL){
        return;
    }
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        node *current = Q.front();
        cout<<current->data;
        Q.pop();
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        
    }
}

int main() {
    
}
