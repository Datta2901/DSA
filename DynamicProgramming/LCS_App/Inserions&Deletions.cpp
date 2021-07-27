// Problem number of insertions and deletions required to convert s1 into s2 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dp(20,vector<int>(20, -1));

int LongestCommonSubsequence(string a,string b){
    int m = a.size(),n = b.size();
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string a,b; 
    cin >> a >> b;
    int common = LongestCommonSubsequence(a,b);
    cout << "Minimum number of deletions : " << (a.size() - common)<< endl;
 
    cout << "Minimum number of insertions : " << (b.size() - common)<< endl;
    cout << "Total : " << (a.size() + b.size() - (2 * common)) << endl;

    return 0;
}
