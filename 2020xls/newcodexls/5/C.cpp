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
int ans = 0;

/*
??????:
???, ???,???
??(q, 0, n - 1);
*/
int temp[maxn];
int q[maxn];
ll con = 0;//???Count Inversions, ????
//int bsearch_1(int l, int r)
//{
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (check(mid)) r = mid;
//        else l = mid + 1;
//    }
//    return l;
//}
void merge_sort(int q[], int l ,int r)
{
	memset(q, 0, sizeof q);
    if (l >= r)
        return;
    int mid = l + r >> 1;
    //??
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

//    merge(q + l, q + mid + 1, q + mid + 1, q + r + 1, temp);
    //??
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else//???Count Inversions
        {
            con += mid - i + 1;
            temp[k++] = q[j++];
        }

    while (i <= mid)
    {
        temp[k++] = q[i++];
    }

    while (j <= r)
    {

        temp[k++] = q[j++];
    }


    //?????
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
}

void update(int a[], int n) {
	int tem = a[n - 1];
	for (int i = n - 1; i >= 1; i--) {
		a[i] = a[i - 1];
	}
	a[0] = tem;
//	for (int i = 0 ; i< n; i++) cout << a[i] <<' ';
}
int dp[1000];
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = read();
		dp[i] = 1;
	}
	ans = -INF;
	for (int i = 0; i < n; i++) {
		fill(dp, dp + 1000, 1);
		update(a, n);
//		for (int j = 0 ; j < n; j++) {
//			cout << a[j] << ' ';
//		}
//		puts("");
		for (int k = 0; k < n; k++)
    	{
        	for (int j = 0; j < k; j++)
        	{
            	if (a[k] > a[j])
                	dp[k] = max(dp[k], dp[j] + 1);
        	}
    	}
		int tem = *max_element(dp, dp + n);
    	if (ans < tem) {
    		ans = tem;
//    		cout << i << ' ' << ans  << endl;
		}
    	
	}
//	cout << ans << endl;
	cout << n - ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

