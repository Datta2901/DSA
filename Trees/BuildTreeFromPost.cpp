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


int searchPostion(int inorder[],int start,int end,int ele){
    for (int i = start; i <= end; i++){
       if(inorder[i] == ele){
           return i;
       }
    } 
}

Node* BuildTree(int inorder[],int postorder[],int start,int end){
    static int index = end;
    if(start > end){
        return NULL;
    }
    int curr = postorder[index];
    index--;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = searchPostion(inorder,start,end,curr);
    node->rchild = BuildTree(inorder,postorder,pos + 1,end);
    node->lchild = BuildTree(inorder,postorder,start,pos - 1);
    return node;
}


Node* Inorder(Node* root){
    if(root){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}

int main(){
    int size;
    cin >> size;
    int postorder[size],inorder[size];
    cout << "Enter postorder traversal : ";
    for(int i = 0; i < size; i++){
        cin >> postorder[i];
    }
    cout << "Enter Inorder traversal : ";
    for(int i = 0; i < size; i++){
        cin >> inorder[i];
    }
    Node* root = BuildTree(inorder,postorder,0,size - 1);
    Inorder(root);  
    cout << endl;
    return 0;
}

/*  
    Sample Input
    5
    Enter postorder traversal : 4 2 5 3 1 
    Enter Inorder traversal : 4 2 1 5 3
*/