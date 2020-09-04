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
multiset<int>S;
void solve()
{
	S.insert(-2147483647);
	S.insert(2147483647);
	n = read();
	while (n--) {
		int t = read(), x = read(), order;
		if (t == 1) {
			auto it=S.lower_bound(x);
            
            order=0;
            
            for(auto i=S.begin();i!=it;i++,order++);
            
            printf("%d\n",order);
            //Êä³öorder¼´Îª´ð°¸
		} else if (t == 2) {
            order=-1;

            for(int i:S)
                if(++order==x) {
                	printf("%d\n",i);break;
				}
                    		
		} else if (t == 3) {
			auto it=S.lower_bound(x);
			printf("%d\n",*--it);
		} else if (t == 4) {
			printf("%d\n",*S.upper_bound(x));
		} else {
			S.insert(x);
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

