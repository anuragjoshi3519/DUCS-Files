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
    
    void preOrderTraversal(node* r){
        if(r==NULL)return;
        cout<<r->val<<" ";
        preOrderTraversal(r->left);
        preOrderTraversal(r->right);
    }
};

int main(){
    int n;
    BinaryTree binaryTree;
    cout<<"Enter number of nodes in the tree: ";
    cin>>n;
    int postOrder[n],inOrder[n];
    unordered_map<int,int> inMap;

    cout<<"Enter in order traversal: ";
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
        inMap[inOrder[i]] = i;
    }

    cout<<"Enter post order traversal: ";
    for(int i=0;i<n;i++){
        cin>>postOrder[i];
    }      

    binaryTree.root = new node(postOrder[n-1]);

    for(int i=n-2;i>=0;i--){
        node* r = binaryTree.root;
        while(true){
            if(inMap[postOrder[i]]<=inMap[r->val]){
                if(r->left!=NULL)
                    r=r->left;
                else{
                    r->left = new node(postOrder[i]);
                    break;
                }    
            }    
            else{
                if(r->right!=NULL)
                    r=r->right;
                else{
                    r->right = new node(postOrder[i]);
                    break;
                }
            }
        }
    }
    cout<<"Pre Order Traversal: ";
    binaryTree.preOrderTraversal(binaryTree.root);
    return 0;
}