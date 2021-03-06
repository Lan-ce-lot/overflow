# Codeforces Round #698 (Div. 2)补题

## C

[C. Nezzar and Symmetric Array](https://codeforces.com/contest/1478/problem/C)



### 题意

原来有2*n个数，各不相同，这2*n个数中，每个数的相反数也在其中。
Nezzar在100万年前计算出了 每个数与其他数的差值 的和，但忘掉了原来那2*n个数。
问从这2*n个计算出来的差值和能不能推出一个满足条件的2*n个数。

### 思路

发现公式，例如有d1, d2, d3, d4从小到达排列

d4 = 4 * a4 * 2

d3 = (3 * a3 + a4) * 2

d2 = (2 * a2 + a3 + a4) * 2

d1 = (a1 + a2 + a3 + a4) * 2

显然可以推出所有元素

只要中途不出现非正整数即可

### 代码

```c++
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
ll a[maxn], tmp[maxn];

void solve()
{
	t = read();
	while (t--) {
		map<ll, int> M;
		n = read();
		bool flag = 0;
		for (int i = 0; i < n * 2; i ++) {
			a[i] = read();
		}
		sort(a, a + 2 * n);
		for (int i = 0; i < n * 2; i++) {
			M[a[i]]++;
			if (a[i] & 1) { // 必须为偶数 
				flag = 1;
			}
		}
		for (int i = 0; i < n * 2; i++) {
			if (M[a[i]] != 2) { // 必须成对出现 
				flag = 1;
			} 
		}
		ll ddd = 0, summ = 0;
		for (int i = 1; i <= n; i++) {
			tmp[i] = a[(i - 1) * 2];
		}
		for (int i = n; i >= 1; i--) {
			if ((tmp[i] / 2 - summ) <= 0 || (tmp[i] / 2 - summ) % i) {
				flag = 1;break;
			}
			ddd = (tmp[i] / 2 - summ) / i;
			summ += ddd;
		} 
		
		if (flag == 0) {
			puts("YES"); 
		} else {
			puts("NO");
		}
	}
}
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```



## 小结

害，还是差一点时间，: (





