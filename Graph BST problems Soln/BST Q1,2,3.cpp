#include<iostream>

using namespace std;
/*
Task 1: Implement Basic BST Operations
Problem: Write a program to implement insertion and searching in a BST.
Example Input:
• Insert: 50, 30, 70, 20, 40, 60, 80
• Search: 40, 90
Example Output:
Search Result:
40: Found
90: Not Found

Task 2: Traversals in a BST
Problem: Write a program to perform Preorder, Inorder, and Postorder traversals in a
BST.
Example Input:
• Insert: 50, 30, 70, 20, 40, 60, 80
Example Output:
Inorder Traversal: 20 → 30 → 40 → 50 → 60 → 70 → 80
Preorder Traversal: 50 → 30 → 20 → 40 → 70 → 60 → 80
Postorder Traversal: 20 → 40 → 30 → 60 → 80 → 70 → 50

Task 3: Find the Minimum and Maximum in a BST
Problem: Write a program to find the minimum and maximum value in a BST.
Example Input:
• Insert: 50, 30, 70, 20, 40, 60, 80
Example Output:
Minimum Value: 20
Maximum Value: 80
*/

struct node{
    int data;
    node *left;
    node *right;

    node(int v){
        data=v;
        left=NULL;
        right=NULL;

    }
};

node* insertnode(node *root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(root->data > val){
        root->left=insertnode(root->left,val);
    }
    if(root->data < val){
        root->right=insertnode(root->right,val);
    }
    return root;
}

void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* findmin(node *root){
    node *ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
    return ptr;
}

node *findmax(node *root){
    node *curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr;
}

bool search(node *root,int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(val< root->data){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

int main(){

node *root=NULL;

root=insertnode(root,50);
root=insertnode(root,30);
root=insertnode(root,70);
root=insertnode(root,20);
root=insertnode(root,40);
root=insertnode(root,60);
root=insertnode(root,80);

cout<<"Preorder:    ";
preorder(root);

cout<<endl<<"Postorder:    ";
postorder(root);

cout<<endl<<"Inorder:    ";
inorder(root);

node *minimum=findmin(root);

cout<<endl<<"minimum value:   "<<minimum->data;

node *maximum=findmax(root);

cout<<endl<<"maximum value:   "<<maximum->data;

bool found=search(root,40);

if(found){
    cout<<endl<<"Found!";
}
else{
    cout<<endl<<"Not Found!";
}

}
