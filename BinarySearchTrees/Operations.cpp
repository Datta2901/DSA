#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* lchild;
    int data;
    Node* rchild;
    Node(int val){
        rchild = NULL;
        data = val;
        lchild = NULL;
    }
}*root = NULL;

void insert(int val){
    Node *temp = root,*newnode,*prev;
    newnode = new Node(val);
    if(root == NULL){
        root = newnode;
        return;
    }
    while(temp != NULL){
        prev = temp;
        if(temp->data < val){
            temp = temp->rchild;
        }else if(temp->data > val){
            temp = temp->lchild;
        }else{
            //if it it equal
            return;
        }
    }

    if(prev->data > val){
        prev->lchild = newnode;
    }else{
        prev->rchild = newnode;
    }
}

void Inorder(Node *root){
    if(root){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}


Node* search(int key){
    Node *temp = root;
    while(temp){
        if(temp->data == key){
            return temp;
        }else if(temp->data > key){
            temp = temp->lchild;
        }else{
            temp = temp->rchild;
        }
    }
}

// Function to insert the nodes of the bst recursively
Node* RecurInsert(Node* root,int val){
    if(root == NULL){
        Node* newNode = new Node(val);
        return newNode;
    }
    if(root->data > val){
        root->lchild = RecurInsert(root->lchild,val);
    }else if(root->data < val){
        root->rchild = RecurInsert(root->rchild,val);
    }
    return root;
}

Node* Height(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(Height(root->lchild),Height(root->rchild)) + 1;
}

Node* InOrderPredecessor(Node *root){
    while(root && root->rchild){
        root = root->rchild;
    }
    return root;
}

Node* InorderSuccessor(Node *root){
    while(root && root->lchild){
        root = root->lchild;
    }
    return root;
}

Node* Delete(Node* root,int key){
    Node* temp;
    if(root == NULL){
        return NULL;
    }
    if(root->lchild == NULL && root->rchild == NULL){
        if(root == NULL){
            return NULL;
        }
        delete(root);
        return NULL;
    }
    if(root->data < key){
        root->lchild= Delete(root->lchild,key);
    }else if(root->data > key){
        root->rchild = Delete(root->rchild,key);
    }else{
        if(Height(root->lchild) > Height(root->rchild)){
            temp = InOrderPredecessor(root->lchild);
            root->data = temp->data;
            root->lchild = Delete(root->lchild,temp->data);
        }else{
            temp = InorderSuccessor(root->rchild);
            root->data = temp->data;
            root->rchild = Delete(root->rchild,temp->data);
        }
    }
    return root;
}



int main(){ 
    cout << "Enter the size of the BST" << endl;
    int size;
    cin >> size;
    Node* root = NULL;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        // insert(a);
        root = RecurInsert(root,a);
    }
    Inorder(root);
    cout << endl;
    cout << "Enter Number of elements to be deleted : ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        root = Delete(root,a);
    }  
    cout << "Enter the element to be search" << endl;
    int s;
    cin >> s;
    Node* temp = search(s);
    if(temp){
        cout << "given element " << temp->data << " found in Given BST" << endl;
    }else{
        cout << "Element is not found" << endl;
    }

    Inorder(root);

    return 0;
}