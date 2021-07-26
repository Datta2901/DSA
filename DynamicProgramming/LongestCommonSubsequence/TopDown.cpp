// Time Complexity is O(m * n )
// Top down approach
// As recursion goes upto  calls from higher functions to base case
// so we are going to the Top to bottom 
// Memoization

#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a,string b,int m,int n){

    vector<vector<int> > mat(m + 1,vector<int>(n + 1, -1));
    if(mat[m][n] != -1){
        return 0;
    }
    if(m == 0 || n == 0){
        mat[m][n] = 0;
    }else{
        if(a[m - 1] == b[n - 1]){
            mat[m][n] = 1 + LongestCommonSubsequence(a,b,m - 1,n - 1);
        }else{
            mat[m][n] = (max(LongestCommonSubsequence(a,b,m - 1,n),LongestCommonSubsequence(a,b,m,n-1)));
        }
    }
    return mat[m][n];
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << "Length of Longest Common Subsequence is : " << LongestCommonSubsequence(a,b,a.size(),b.size()) << endl;
    // for(auto it : mat){
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}