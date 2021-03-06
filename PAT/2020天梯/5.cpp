#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
int n, m, p;
int ma[10][10];
int a[maxn];

bool vis[100];
int hx[maxn], d;
typedef long long ll;

struct node {
	char a;
	string b;
	int type;
	string time;
}N[maxn];

vector<pair<int, int> > G[maxn];
int main()  {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back();
		G[b].push_back();
		
	} 
	
	return 0;
}
