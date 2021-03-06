# Codeforces Round #696 (Div. 2)补题

## C. Array Destruction

[C. Array Destruction](http://codeforces.com/contest/1474/problem/C)



### 题意

> 给定长度为2n的数组，一开始选定一个数X，将数组中的两个和为X的数a和b删除，同时令X=max(a,b)，重复该动作，直到数组所有元素删除完毕。如果能，输出YES和步骤，不能输出NO。

### 思路

分解后的两个数一定是数组中可利用的的最大值和其中的某一个数

反证法：假设被分解的数不是可利用的最大的数，那么这个最大的数在之后的分解中必不能再被用到， 因为它太大了，将会大于欲分解的数 

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
int t, n, a[maxn], flag = 0;
multiset<int> S;
vector<int> ANS;
void solve()
{
	t = read();
	while (t--) {
		flag = 0;
		n = read();
		for (int i = 0; i < n * 2; i++) {
			a[i] = read();
		}
		sort(a, a + 2 * n);
		for (int i = 0; i < n * 2 - 1; i++) {
			int x = a[i] + a[2 * n - 1];
			S.clear();
			ANS.clear();
			for (int j = 0; j < 2 * n; j++) {
				S.insert(a[j]);
			}

			for (int j = 0; j < n; j++) {
				auto itend = S.end();
				itend--;
				int y = x - *itend;
				S.erase(itend);
				auto it2 = S.find(y);
				if (it2 == S.end()) {
					break;
				} else {
					ANS.push_back(x - y);
					ANS.push_back(y);
					x = max(y, x - y);
					S.erase(it2);
				}
			}
			
			
			if (ANS.size() == n * 2) {
				puts("YES");
				cout << ANS[0] + ANS[1] << endl;
				for (int i = 0; i < ANS.size(); i+=2) {
					cout << ANS[i] << ' ' << ANS[i + 1] << endl;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
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





## D. Cleaning

[D. Cleaning](https://codeforces.com/contest/1474/problem/D)



### 题意

> 有n堆石头，第i堆有ai个石头。i和i+1是所有1≤i≤n−1的相邻桩。如果桩i变空，桩i−1和i+1不会成为相邻的。
>
> 选择两个相邻的桩，如果两个桩都不是空的，则从每个桩中移除一块石头。在开始清理之前，可以选择两个相邻的桩并交换它们。确定是否可以使用超高性能去除所有结石，但不能超过一次。
>
> 打印“是”或“否”

### 思路

首先发现,端点一定要<=后面的值，不然肯定不成立

于是a2>=a1,减了之后a2=a2-a1;此时a2变成端点，同理可知a3>=此时的a2才能成立.

那么对于从尾巴开始也是这个道理。

那么中间的过程用一个前缀去记录。也就是用前缀表示前后相邻能相减，那么此时后面的这个数变成了多少。后缀同理

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
#define debug(a) cout<<#a<<"="<<a<<endl;
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
int t, n, a[maxn];
int pre[maxn], nex[maxn];

void solve()
{
	t = read();
	while (t--) {
		n = read();
		for (int i = 0; i < n + 10; i++) {
			pre[i] = nex[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		
		for (int i = 1; i <= n; i++) {
			if (pre[i - 1] > a[i]) {
				pre[i] = INF / 2;
			} else {
				pre[i] = a[i] - pre[i - 1];
			}
		} 
		
		for (int i = n; i >= 1; i--) {
			if (nex[i + 1] > a[i]) {
				nex[i] = INF;
			} else {
				nex[i] = a[i] - nex[i + 1];
			}
		}
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (pre[i] == nex[i + 1]) {
				flag = 1;
				break;
			} else {
				int A = a[i], B = a[i + 1];
				
				if (A >= nex[i + 2] && B >= pre[i - 1]) {
					A -= nex[i + 2];
					B -= pre[i - 1];
					if (A - B == 0) {
						flag = 1;
						break;
					}
				}
			}
		}
		
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
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

菜鸡a两题，B两次罚时，因为情况没有考虑清楚。

C题暴搜wa两发，一开始思路是对的，却没动手写。

## 参考

>https://blog.csdn.net/qq_43857314/article/details/112855909s
>
>https://blog.csdn.net/zstuyyyyccccbbbb/article/details/112862389