/*  
    This program consists How to take input of a binary tree using queue
    implemented using LinkedList
    And then implemented Basic Tree Traversals of tree
    
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
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p){
    if (p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p){
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main(){
    Treecreate();
    cout << endl;
    cout << "Preorder Traversal : ";
    Preorder(root);
    printf("\nPost Order Traversal : ");
    Postorder(root);
    cout << endl;
    cout << "Inorder Order Traversal : ";
    Inorder(root);
    cout << endl;
    return 0;
}