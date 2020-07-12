#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
int dp[maxn][maxn];
 
int main()
{
    string s,t;
    cin>>s>>t;
    n = s.length();
    m = t.length();
    for(int i=0;i<n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
        }
    }
    if(dp[n][m] <= 2)puts("YES");
    else puts("NO");
    return 0;
}
