#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int son[2505][26], cnt[2505], idx, n;
void insert(string s)
{
    int p = 0;
    for (int i = 0; i<s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}
ll dfs(int root) {
	ll a=1;
	for(int i=0;i<26;++i)
		if(son[root][i]>0)
			a*=dfs(son[root][i]);
	return a+cnt[root];
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		getline(cin, s);
		insert(s);
	}
	printf("%lld",dfs(0));
	return 0;
}

