#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

    node* insertion(node *root, int val){
        if(root==NULL){
            return new node(val);
        }
        if(root->data > val){
            root->left=insertion(root->left,val);
        }
        if(root->data < val){
            root->right=insertion(root->right,val);
        }
        return root;
    }
    bool search(node *root,int val){
        if(root==NULL){
            return false;
        }
        if(root->data==val){
            return true;
        }
        if(val< root->data){
            return search(root->left,val);
        }
        if(val> root->data){
            return search(root->right,val);
        }
    }
    void pre(node *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        pre(root->left);
        pre(root->right);
    }
    void in(node *root){
        if(root==NULL){
            return;
        }
        in(root->left);
        cout<<root->data<<" ";
        in(root->right);
    }
    void post(node *root){
        if(root==NULL){
            return;
        }
        post(root->left);
        post(root->right);
        cout<<root->data<<" ";
    }
    node* findmax(node *root){
        node *ptr=root;
        while(ptr->right!=NULL){
            ptr=ptr->right;
        }
        return root;
    }
    node* findmin(node *root){
        node *ptr=root;
        while(ptr->left!=NULL){
            ptr=ptr->left;
        }
        return root;
    }

    node* deletenode(node *root, int val){
        if(root==NULL){
            return NULL;
        }
        if(root->data < val){
            deletenode(root->right,val);
        }
        else if(root->data > val){
            deletenode(root->left,val);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->right==NULL){
                node *temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL){
                node *temp=root->right;
                delete root;
                return temp;
            }
            else{
                node *temp=findmin(root->right);
                root->data=temp->data;
                root->right=deletenode(root->right, temp->data);
            }
        }
        return root;
    }

int main(){

node *root=NULL;

root=insertion(root,50);
root=insertion(root,30);
root=insertion(root,70);
root=insertion(root,20);
root=insertion(root,40);
root=insertion(root,60);
root=insertion(root,80);

bool found=search(root,100);
if(!found){
    cout<<"Not found!";
}
else{
    cout<<"Found!";
}

cout<<endl;
cout<<"Preorder:    ";
pre(root);

cout<<endl<<"inorder:    ";
in(root);

cout<<endl<<"postorder:    ";
post(root);

node *maxi=findmax(root);
cout<<endl<<"Max value:     "<<maxi->data;

node *mini=findmin(root);
cout<<endl<<"Minimum value:     "<<mini->data;

root=deletenode(root, 70);
cout<<endl<<"inorder traversal after deletion:    ";
in(root);

}
