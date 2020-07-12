/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
const int N= 31;
struct Pond
{
	int order,f,d;
	friend bool operator < (const Pond &t1,const Pond &t2) {
		if(t1.f == t2.f)
			return t1.order > t2.order;
		return t1.f < t2.f;
	}
}Ponds[N];
int dis[N];
int times[N][N];
int main()
{
	int n,T;
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&T);
		T = T*12;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&Ponds[i].f);
			Ponds[i].order = i;
		}
		for(int i=1;i<=n;i++)	scanf("%d",&Ponds[i].d);
		for(int i=1;i<n;i++)	scanf("%d",&dis[i]);
		memset(times,false,sizeof times);

		int MaxFish = 0;
		int MaxPond = 1;
		int MaxFish_t;
		int t;
		for(int i=1;i<=n;i++)
		{
			t = T;
			priority_queue<Pond> P;
			for(int j=1;j<=i;j++)   P.push(Ponds[j]);
 			for(int j=1;j<i;j++)   t -= dis[j];
			MaxFish_t = 0;
			Pond temp;
			for(int j=1;j<=t;j++)
			{
				temp = P.top();
				MaxFish_t += temp.f;
				temp.f = max(temp.f - temp.d,0);
				times[i][temp.order]++;
				P.pop();
				P.push(temp);
			}
			if(MaxFish_t > MaxFish)
			{
				MaxFish = MaxFish_t;
				MaxPond = i;
			}
		}
		for(int i=1;i<n;i++)	printf("%d, ",times[MaxPond][i]*5);
		printf("%d\n",times[MaxPond][n]*5);
		printf("Number of fish expected: %d\n\n", MaxFish);
	}
}



