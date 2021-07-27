#include<bits/stdc++.h>
using namespace std;

// The diff utility is a data comparison tool that calculates and displays the differences between the two texts. 
// It tries to determine the smallest set of deletions and insertions and create one text from the other. 
// Diff is line-oriented rather than character-oriented, unlike edit distance.

int dp[20][20];

void DiffUtility(string a,string b,int m,int n){
    // If character matches
    if(m > 0 && n > 0 &&a[m - 1] == b[n - 1]){
        DiffUtility(a,b,m - 1, n - 1);
        cout << " " << a[m - 1];
    }// if the current character of `b` is not present in `a`
    else if(n > 0 && (m == 0 || dp[m][n - 1] >= dp[m - 1][n])){
        DiffUtility(a,b,m, n -1);
        cout << " +" << b[n - 1];
    }// if the current character of `a` is not present in `b`
    else if(m > 0 && (n == 0 || dp[m][n - 1] < dp[m - 1][n])){
        DiffUtility(a,b,m - 1, n);
        cout << " -" << a[m - 1]; 
    }
}

void  LongestCommonSubsequence(string a,string b){
    int m = a.size(),n = b.size();
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
}

int main(){
    string a,b;
    cin >> a >> b;
    int m = a.size(),n = b.size();
    LongestCommonSubsequence(a,b);
    DiffUtility(a,b,m,n);
    cout << endl;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
