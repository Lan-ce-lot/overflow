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
const int maxn = 100005;
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
int t, n;
int a[100005];
//map<int, int> M;
int num[11];
vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    reverse(C.begin(), C.end());
    return C;
}
vector<int> A;
vector<int> ANS;
void solve()
{
	t = read();
	while (t--) {
		memset(num, 0, sizeof num);
		A.clear();
		ANS.clear();
		n = read();
		int min1 = INF;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			if (a[i] != 0) {
				min1 = min(min1, a[i]);
			}
			num[a[i]]++;
		}
		int b = min1;
		num[b]--;
		int fi = INF;
		for (int i = 1; i <= 9; i++) {
			if (num[i] >= 1) {
				fi = i;
				break;
			}
		}
		num[fi]--;
		A.push_back(fi);
		int con0 = num[0];
		
//		if (con0 <= 0) continue;
		if (con0 > 0) {
			while (con0--) {
				A.push_back(0);
			}	
		}

		for (int i = 1; i <= 9; i ++) {
			int con = num[i];
			if (num[i] <= 0) continue;
			while (con--) {
				A.push_back(i);
			}
		}
		reverse(A.begin(), A.end());
		ANS = mul(A, b);
		
		for (auto i : ANS) {
			cout << i;
		}
		puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

