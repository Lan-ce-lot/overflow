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
const int maxn = 1005;
ll t, n;

int flag = 0;
void dfs(ll x, int t)
{
    if (t > 19 || flag==1)
        return;
    if (!(x % n) && x != n)
    {
        cout << x << endl;
        flag = 1;
        return;
    }
    dfs(x * 10, t + 1);
    dfs(x * 10 + 1, t + 1);

    return;
}

void solve()
{
    while (~scanf("%lld", &n))
    {
        flag = 0;
        if (n == 0)
            return;
        dfs(1, 1);
    }
}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <algorithm>
//#include <cmath>
//#include <deque>
//#include <vector>
//#include <queue>
//#include <string>
//#include <cstring>
//#include <map>
//#include <stack>
//#include <set>
//#include <sstream>
//#define mod 1000000007
//#define eps 1e-6
//#define ll long long
//#define INF 0x3f3f3f3f
//#define MEM(x,y) memset(x,y,sizeof(x))
//#define Maxn 110
//using namespace std;
//int n,flag;
//void dfs(int step,long long y)//step为数的长度，y为要寻找的数
//{
//    if(step>19 || flag==1)//利用flag保证找到这个数的时候终止
//        return;
//    if(y%n==0)
//    {
//        flag=1;
//        cout << y << endl;
//        return;
//    }
//    dfs(step+1,y*10);//两个方向
//    dfs(step+1,y*10+1);
//}
//int main()
//{
//    while(cin >> n)
//    {
//        if(n==0)
//            break;
//        flag=0;
//        dfs(1,1);//从1开始深搜，初始阶段长度为1
//    }
//}
