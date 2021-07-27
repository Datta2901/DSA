#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    map<char,int>first;
    for(int i = 0; i < a.size(); i++){
        first[a[i]]++;
    }
    int common = 0;
    for(int i = 0; i < b.size(); i++){
        if(first[b[i]] > 0){
            common++;
            first[b[i]]--;
        }
    }
    cout << a.size() + b.size() -(2 * common)<< endl;
    return 0;
}