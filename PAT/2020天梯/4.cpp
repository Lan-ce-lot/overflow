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
bool cmp(node a, node b) {
	if (a.time != b.time)
	return a.time < b.time;
	else
	return a.type > b.type;
}
int main()  {
	
	cin >> d >> p;
	while (d--) {
		int sq, me;
		cin >> sq >> me;
		int con = 0;
		for (int i = 0; i < sq;i ++) {
			node tem;
			cin >> tem.a >> tem.b >> tem.type >> tem.time;
			if (tem.b.size() != 18) {
				continue;
			}
			N[con++] = tem;
		}
		sort(N, N + con, cmp);
		
//		cout << "*";
		for (int i = 0; i < me; i++) {
			cout << N[i].a << ' ' << N[i].b << ' ' << N[i].type << ' ' << N[i].time << endl;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		cin >> hx[i];
//	}
	
	
	return 0;
}
