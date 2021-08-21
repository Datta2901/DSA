/*
    Build Tree from inorder and preorder Traversals of the tree
    https://youtu.be/HJKoNLGRnYk
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* rchild;
    int data;
    Node* lchild;
    Node(int val){
        rchild = NULL;
        lchild = NULL;
        data = val;
    }
};

int searchPosition(int inorder[],int start,int end,int ele){
    for(int j = start; j <= end; j++){
        if(inorder[j] == ele){
            return j;
        }
    }
}

Node* BuildTree(int inorder[],int preorder[],int start,int end){
    static int index = 0;
    if(start > end){
        return NULL;
    }
    int curr = preorder[index];
    index++;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = searchPosition(inorder,start,end,curr);
    node->lchild = BuildTree(inorder,preorder,start,pos - 1);
    node->rchild = BuildTree(inorder,preorder,pos + 1,end);
    return node;
}

void Inorder(Node* root){
    if(root != NULL){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}

int main(){
    int size;
    cin >> size;
    int preorder[size],inorder[size];
    cout << "Enter preorder traversal : ";
    for(int i = 0; i < size; i++){
        cin >> preorder[i];
    }
    cout << "Enter Inorder traversal : ";
    for(int i = 0; i < size; i++){
        cin >> inorder[i];
    }
    Node* root = BuildTree(inorder,preorder,0,size - 1);
    Inorder(root);  
    cout << endl;
    return 0;
}