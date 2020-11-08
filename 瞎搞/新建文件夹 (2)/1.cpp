/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5;
struct node
{
    int x;
    string str;
}a[maxn];

bool cmp(node a, node b)
{
    if (a.x == b.x)
        return a.str < b.str;
    return a.x > b.x;
}
bool cmp1(node a, node b)
{
    return a.str > b.str;
}
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
int t, n;
int main()
{
//    ios::sync_with_stdio(false);
	int n;
	scanf("%d\n",&n);
	char name[n][101];
	char str[101]={0};
	for(int i=0;i<n;i++){
		scanf("%s[^\n]",str);
		strcpy(name[i],str);
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", name[i]);
	}
    return 0;
}

