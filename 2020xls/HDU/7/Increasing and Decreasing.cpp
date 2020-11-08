#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<time.h> 
#include<climits>
#define debug(a) cout << "*" << a << "*" << endl
#define ls	(k << 1)
#define rs	((k << 1) | 1)
#define mid	((l + r) >> 1)
using namespace std;
typedef long long ll;
int t, n, x, y;
int a[100005];
int main()
{
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &x, &y);
		if (x + y > n + 1 || y <= (n - y) / (x))
			puts("NO");
		else {
			puts("YES");
			for (int i = 1; i < n; i++) {
			
			}
			for (int i = 1; i <= n; i ++) {
				if (i == 1) printf("%d", a[i]);
				else printf(" %d", a[i]);
			}
			puts("");
		}
	}
}

