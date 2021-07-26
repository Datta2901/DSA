#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a,string b,int m,int n){
    // Using Recursion
    if(m == 0 || n == 0){
        return 0;
    }
    if(a[m - 1] == b[n - 1]){
        return 1 + LongestCommonSubsequence(a,b,m - 1,n - 1);
    }else{
        return (max(LongestCommonSubsequence(a,b,m - 1,n),LongestCommonSubsequence(a,b,m,n-1)));
    }
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << "Length of Longest Common Subsequence is : " << LongestCommonSubsequence(a,b,a.size(),b.size()) << endl;
    return 0;
}