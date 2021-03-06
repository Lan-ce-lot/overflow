/*
第二类stirling
+高精度 
状态转移方程
S(n,m)=S(n-1,m-1)+S(n-1,m)*m 
*/ 
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> dp[105][105];
vector<int> mul(vector<int> A, int B){
    vector<int> C;
    reverse(A.begin(), A.end());
    int t = 0;
    for (int i = 0; i < A.size() || t; i++){
        if (i < A.size())
            t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    reverse(C.begin(), C.end());
    return C;
}
vector<int> add(vector<int> A,vector<int> B){
    vector<int> C;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++){
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    reverse(C.begin(), C.end());
    return C;
}

int main(){
	for (int i = 1; i <= 100; i++)
		dp[i][1].push_back(1);
	for (int i = 2; i <= 100; i++) 
		for (int j = 1; j <= i; j++)
			dp[i][j] = add(mul(dp[i - 1][j], j),dp[i - 1][j - 1]);
	while (~scanf("%lld%lld",&n,&m)) {
		if (n<m)cout<<0;
		else
			for (int i = 0; i < dp[n][m].size(); i++) 
				cout << dp[n][m][i];
		puts("");
	} 
}
