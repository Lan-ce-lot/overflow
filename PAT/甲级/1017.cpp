#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

int rate[250000];
struct node{
	int come, time;
	
	bool operator < (const node &W) const {
		return come < W.come;
	} 
}N[1050000];
// int a[105]; 
int n, k;
int main() {
//	cin >> ; 
	
	cin >> n >> k;
	int tem;
	int con = 0;
	for (int i = 0; i < n; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		scanf("%d", &tem);
		if (h * 3600 + m * 60 + s > 17 * 3600) continue;
		N[con].come = h * 3600 + m * 60 + s;
		N[con++].time = tem * 60;
//		cout << h << m << s;
	}
	
	sort(N, N + con);
	priority_queue<int, vector<int>, greater<int> > Q;// ´ó¸ù¶Ñ 
	for (int i = 0; i < k; i++) {
		Q.push(28800);
	}
	int sum = 0;
	for (int i = 0; i  < con; i++) {
		if (Q.top() <= N[i].come) {
			Q.push(N[i].come + N[i].time);
			Q.pop(); 
		} else {
			sum += Q.top() - N[i].come;
			Q.push(Q.top() + N[i].time);
			
			Q.pop();
		}
		
	}
	printf("%.1f\n", sum * 1.0 / con / 60); 
	
	return 0;
}
