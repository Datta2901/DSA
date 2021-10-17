#include<bits/stdc++.h>
using namespace std;

const int size = 1e6 + 1;
int arr[size];

// Let N be the size of the input
//  Actual size of the segment tree is (2 * 2 ^(power (ceil(log2(N)))) -  1) <= 4 * N
// so we will use 4 * N for our convience
int seg[4 * size];

// [Low,high] are the range of the node in segment tree
//  index is the index of the segment tree
void build(int low,int high,int index){
    if(low == high){
        seg[index] = arr[low];
    }else{
        int mid = low + (high - low ) / 2;
        build(low,mid,2 * index + 1);           //left subtree
        build(mid + 1,high,2 * index + 2); // right subtree
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
}

// [l,r] --> given query
// [low,high] --> node in segment tree
int query(int low,int high,int index,int l,int r){
    // Completely Outside
    if( high < l || low > r){
        return 0;
    }
    // Completely inside range
    if(l <= low && r >= high){
        return seg[index];
    }
    int mid = low + (high - low) / 2;
    return query(low,mid,2 * index + 1,l,r) + query(mid + 1,high,2 * index + 2,l,r);
}

void update(int low,int high,int pos,int index,int diff){
    if(pos < low  || pos > high){
        return;
    }
    // if it is in the range of user input 
    // we simply add the diff
    seg[index] = seg[index] + diff;
    if(low < high){
        int mid = (low + high)/ 2;
        update(low,mid,pos,2 * index + 1,diff);
        update(mid + 1,high,pos,2 * index + 2,diff);
    }
}



void printSeg(int seg[],int size){
    cout << "Segment Tree is : " << " ";
    for(int i = 0; i <= 4 * size; i++){
        cout << seg[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter the size" << endl;
    int s;
    cin >> s;
    cout << "Enter the elements " << endl;
    for(int i = 0; i < s; i++){
        cin >> arr[i];
    }
    // Building Segment Tree
    build(0,s - 1,0);
    printSeg(seg,s);
    //Query
    cout << "Enter number of queries " << endl;
    int q;
    cin >> q;
    while(q--){
        cout << "Enter the query type " << endl;
        int k;
        cin >> k;
        if(k == 1){
            cout << "Enter the query range" << endl;
            int l,r;
            cin >> l >> r;
            cout << query(0,s - 1,0,l,r) << endl;
            // Update
        }else if(k == 2){
            cout << "Enter the position and value to be updated" << endl;
            int pos,val;
            cin >> pos >> val;
            int diff = val - arr[pos];
            arr[pos] = val;
            update(0,s - 1,pos,0,diff);
            printSeg(seg,s);
        }
    }
    return 0;
}


// Time Complexities

// BUilding Segment Tree take O(n) time
// Update,Query Takes O(logn) time
