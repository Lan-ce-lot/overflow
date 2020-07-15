//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <vector>
//using namespace std;
//int cost[101000];
//int n;
//vector<pair<int, int> > G[10005];
////int G[10100][10100];
//int res = -0x3f3f3f3f;
//bool vis[10100];
//int endno = -1;
//void dfs(int no, int co, string str) {
//	
//	if (co > res) res = co, endno = no;
//	for (int i = 0; i < G[no].size(); i++) {
//		int tem = G[no][i].first;
//		
//		int temp = G[no][i].second;
////		cout << tem << endl;
//		if (vis[tem] == 0) {
//			vis[tem] = 1;
//			dfs(tem, co + temp, str + "->" + char(tem + '0'));
//			vis[tem] = 0;
//		}
//	}
////	cout << co << ' ' << str << endl;
////	cout 
////	res = max(co, res);
//}
//
//
//int main() {
////	cost[1] = 11;
//	while (cin >> n) {
//		memset(vis, 0, sizeof vis);res = -0x3f3f3f3f;
//			for (int i = 1; i <= 101000; i++) {
//		cost[i] = cost[i - 1] + i + 10;
////		cout << cost[i] << ' ' << i << endl;
//	}
////	memset(G, -1, sizeof G);
//	for (int i = 0; i < n - 1; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		G[a].push_back(make_pair(b, c));
////		cout << 111 << endl;
//		G[b].push_back(make_pair(a, c));
//	}
//	int ans = -0x3f3f3f3f;
//	vis[1] = 1;
//	dfs(1, 0, "1");
//
//	memset(vis, 0, sizeof vis);
//	char c[10];
//	sprintf(c, "%d", endno);
//	string s = c;
//	vis[endno] = 1;
//	dfs(endno, 0, s);
//	cout << cost[res] << '\n';
//	}
//
//	
//	return 0;
//}

/* pass %75
*/

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//int cost[100005];
//int n = 0;
//int G[1005][1005];
//int res = -0x3f3f3f3f;
//bool vis[10005];
//void dfs(int no, int co, string str) {
//	vis[no] = 1;
//	for (int i = 1; i <= n; i++) {
//		if (G[i][no] != -1 && vis[i] == 0) {
//			vis[i] = 1;
//			dfs(i, co + G[i][no], str + "->" + char(i + '0'));
//			vis[i] = 0;
//		}
//	}
////	cout << co << ' ' << str << endl;
////	cout 
//	res = max(co, res);
//}
//
//
//int main() {
////	cost[1] = 11;
//	
//	for (int i = 1; i <= 101000; i++) {
//		cost[i] = cost[i - 1] + i + 10;
//	}
//	cin >> n;
////	cout << n;
//	memset(G, -1, sizeof G);
//	for (int i = 0; i < n - 1; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		
////		cin >> G[a][b];
//		G[b][a] = G[a][b] = c;
//	}
////	cout << "*" << endl;
//	
//	int ans = -0x3f3f3f3f;
//	for (int i = 1; i <= n; i++) {
//		memset(vis, 0, sizeof vis);
//		vis[i] = 1;
//		res = -0x3f3f3f3f;
//		char c[10];
//		sprintf(c, "%d", i);
//		string s = c;
//		dfs(i, 0, s);
//		ans = max(res, ans);
//	}
//	cout << cost[ans] << '\n';
//	
//	return 0;
//}
#include <stdio.h>
int main()
{
//	int a[][3]={{1,0,1},{},{1,1}};
	int a[][3] = {{1,2,3},{4,5,6}};
	int i,j;
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%d\t",a[i][j]);
			
			if(j/1!=0)
			{
				printf("\n");
			}
		}
	}
 }

