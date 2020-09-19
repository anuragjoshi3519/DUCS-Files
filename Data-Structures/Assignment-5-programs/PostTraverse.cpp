#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;

    node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
public:
    node* root;

    void postOrderTraversal(node* r){
        if(r==NULL)return;
        postOrderTraversal(r->left);
        postOrderTraversal(r->right);
        cout<<r->val<<" ";
    }
    
};

int main(){
    int n;
    BinaryTree binaryTree;
    cout<<"Enter number of nodes in the tree: ";
    cin>>n;
    int preOrder[n],inOrder[n];
    unordered_map<int,int> inMap;

    cout<<"Enter in order traversal: ";
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
        inMap[inOrder[i]] = i;
    }

    cout<<"Enter pre order traversal: ";
    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }      

    binaryTree.root = new node(preOrder[0]);

    for(int i=1;i<n;i++){
        node* r = binaryTree.root;
        while(true){
            if(inMap[preOrder[i]]<=inMap[r->val]){
                if(r->left!=NULL)
                    r=r->left;
                else{
                    r->left = new node(preOrder[i]);
                    break;
                }    
            }    
            else{
                if(r->right!=NULL)
                    r=r->right;
                else{
                    r->right = new node(preOrder[i]);
                    break;
                }
            }
        }
    }
    cout<<"Post Order Traversal: ";
    binaryTree.postOrderTraversal(binaryTree.root);
    return 0;
}