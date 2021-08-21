/*  
    This program consists How to take input of a binary tree using queue
    implemented using LinkedList
    And then implemented Number of nodes and height of the binary tree
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Treecreate(){
    struct Node *p, *t;
    int x;
    queue<Node*> q;
    printf("Enter root value ");
    cin >> x;
    root = (struct Node*)malloc(sizeof(Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty()){
        p = q.front();
        q.pop();
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

int count(Node *root){
    if(root){
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

int height(Node *root){
    if(root == NULL || (root->lchild == NULL && root->rchild == NULL)){
        return  0;
    }
    return max(height(root->lchild) ,height(root->rchild)) + 1;
}

int main(){
    Treecreate();
    cout << "Count : " << count(root) << endl;
    cout << "Height : " << height(root) << endl;
    return 0;
}