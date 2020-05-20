#include<iostream>
using namespace std;

template<class X>
class BSTNode
{
    public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value){

      left=NULL;
      right=NULL;
      data=value;
    }
};

template<class Y>
class BST{

public:
BSTNode<Y>* root=NULL;

void traverse(BSTNode<Y> * root) {

    if(root){
        traverse(root->left);
        cout<<root->data<<" ";
        traverse(root->right);
    }
}

BSTNode<Y>* findmin(BSTNode<Y>* root){   //to find min value node 
    if(root==NULL)return root;
    BSTNode<Y>* node=root;
    while(root!=NULL){
        if(root->left)node=root->left;
        root=root->left;
    }
    return node;
}

void insert(Y);
BSTNode<Y>* deleteNode(Y,BSTNode<Y>*);

};

template<class Y>
void BST<Y>::insert(Y data){
    BSTNode<Y>* node=new BSTNode<Y>(data);
    BSTNode<Y>* cur=root;
    BSTNode<Y>* parent;
    if(root==NULL){
        root=node;
        return;
    }
    while(cur!=NULL){
        parent=cur;
        if(data<parent->data)
            cur=cur->left;
        else
            cur=cur->right;
    }

    if(parent->data>data)
        parent->left=node;
    else
        parent->right=node;

}

template<class Y>
BSTNode<Y>* BST<Y>::deleteNode(Y data, BSTNode<Y>* root){
    if(root==NULL){cout<<"\nCan't delete, element not found"; return root;}
//..finding node which has the data to be deleted
    if(data<root->data) root->left=deleteNode(data,root->left);
    else if(data> root->data) root->right=deleteNode(data,root->right);

//deletion process
    else{
        if(root->left==NULL && root->right==NULL){//no child case
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){ //one child case
            BSTNode<Y>*temp=root;
            root=root->right;
            delete temp;
        }
         else if(root->right==NULL){ //one child case
            BSTNode<Y>*temp=root;
            root=root->left;
            delete temp;
        }
        else{
          BSTNode<Y>* node = findmin(root->right); //two children
          root->data=node->data;
          root->right=deleteNode(node->data,root->right);
        }
    }
    return root;
}


int main(){

BST<int> tree;
int choice;
int val;
while (true) {
      cout<<"\nMenu::\n";
      cout<<"1.Insert element in BST.\n";
      cout<<"2.Delete element from BST.\n";
      cout<<"3.Print InOrder traversal.\n";
      cout<<"4.Exit.\n";
      cout<<"\nEnter your Choice: ";
      cin>>choice;
      switch (choice) {
         case 1:
            cout << "\nEnter value to be inserted: ";
            cin >> val;
            tree.insert(val);
            cout<<"\nDone.\n";
         break;
         case 2:
            cout << "\nEnter value to be deleted: ";
            cin >> val;
            tree.deleteNode(val,tree.root);
            cout<<"\nDone.\n";
         break;
         case 3:
            cout<<"\nIn order traversal: ";
            tree.traverse(tree.root);
            cout<<"\n";
         break;
         case 4:
            exit(1);
         break;
         default:
            cout<<"\nWrong Choice!!\n";
      }
   }
}