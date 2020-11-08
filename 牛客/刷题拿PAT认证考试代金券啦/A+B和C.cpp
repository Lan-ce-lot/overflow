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
int t, n;
int a[maxn];
//A1 = �ܱ�5����������������ż���ĺͣ�
//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
//A3 = ��5������2�����ֵĸ�����
//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
//A5 = ��5������4��������������֡�
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int A1 = 0, A2 = 0, A3 = 0, co4 = 0,  A5 = 0;
	double A4 = 0.0;
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 10 == 0) {
			A1 += a[i];
		}
		if (a[i] % 5 == 1) {
			if (!flag) {
				flag = 1;
				A2 += a[i];
			} else {
				flag = 0;
				A2 -= a[i];
			}
		}
		if (a[i] % 5 == 2) {
			A3++;
		}
		if (a[i] % 5 == 3) {
			co4++;
			A4 += a[i];
		}
		if (a[i] % 5 == 4) {
			A5 = max(A5, a[i]);
		}
	}
	if (A1 == 0) {
		printf("N ");
	} else {
		printf("%d ", A1);
	}
	if (A2 == 0) {
		printf("N ");
	} else {
		printf("%d ", A2);
	}
	if (A3 == 0) {
		printf("N ");
	} else {
		printf("%d ", A3);
	}
	if (A4 == 0) {
		printf("N ");
	} else {
		printf("%.1f ", A4 / co4);
	}
	if (A5 == 0) {
		printf("N\n");
	} else {
		printf("%d\n", A5);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

