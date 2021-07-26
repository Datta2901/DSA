// Tabulation Method – Bottom Up Dynamic Programming
#include<bits/stdc++.h>
using namespace std;

string LongestCommonSubsequence(string a,string b){
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
    int i = m,j = n;
    string answer = "";
    // Tracing the path in the table
    while(i > 0 && j > 0){
        if(dp[i - 1][j] == dp[i][j - 1]){
            answer += a[i - 1];
            i--;
            j--;
        }
        // or
        // if(a[i - 1] == b[j - 1]){
        //     answer += a[i - 1];
        //     i--;
        //     j--;
        // }
        else if(dp[i][j - 1] > dp[i - 1][j]){
            j--;
        }else{
            i--;
        }
    }
    reverse(answer.begin(),answer.end());
    
    return answer ;
}

int main(){
    string a,b;
    cin >> a >> b;
    cout << "Longest Common Subsequence is : " << LongestCommonSubsequence(a,b) << endl;
    return 0;
}