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
const int maxn = 10005;

int n, a, b;
int is_prime[10005];

void init() {
	for (int i = 2; i * i <= 10000; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				is_prime[j] = 1;
			}
		}
	}
}

pair <int, int> node;
bool vis[maxn];


bool test(int x)
{
    if (x <1000 || x > 9999 || vis[x] || (is_prime[x]))
        return 0;
    return 1;
}

int bit(int x, int k)
{
    int res, ans;
    for (int i = 0; i < k; i++)
    {
        ans = x % 10;
        x /= 10;
    }
//    cout << ans <<endl;
    return ans;
}

void bfs()
{
    queue <pair <int, int> > q;
    q.push(make_pair(a, 0));
    vis[a] = 1;
    while (!q.empty())
    {
        node = q.front();
        if (node.first == b)
        {
//            debug(node.first);
            cout << node.second << endl;
            return ;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (test(node.first - bit(node.first, i + 1) * (pow(10, i)) + j * (pow(10, i))))
                {
//                    cout << node.first - bit(node.first, i + 1) * (pow(10, i)) + j * (pow(10, i)) << ' ' << node.second << endl;
                    q.push(make_pair(node.first - bit(node.first, i + 1) * (pow(10, i)) + j * (pow(10, i)), node.second + 1));
                    vis[int(node.first - bit(node.first, i + 1) * (pow(10, i)) + j * (pow(10, i)))] = 1;
                }
            }
        }
    }
    cout << "Impossible" << endl;
}

void solve()
{
    scanf("%d", &n);
    while (n--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &a, &b);
        bfs();


    }
}

int main()
{
//    ios::sync_with_stdio(false);
int tt = 1733;
//    debug(bit(tt))
//        for (int i = 0; i < 4; i++)
//        {
//            for (int j = 1; j <= 9; j++)
//            {
//                if (test(tt - bit(tt, i + 1) * (pow(10, i)) + j * (pow(10, i))))
//                {
//                    cout << tt - bit(tt, i + 1) * (pow(10, i)) + j * (pow(10, i)) << endl;
//                    vis[int(tt - bit(tt, i + 1) * (pow(10, i)) + j * (pow(10, i)))] = 1;
//                }
//            }
//        }
init();
    solve();
    return 0;
}

