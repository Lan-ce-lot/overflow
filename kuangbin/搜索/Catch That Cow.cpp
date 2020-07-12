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
#define debug(a) cout << "*" << a << "*" << endl
const int maxn = 1e5+10;

struct node
{
    int x;
    int step;
    node(int xx, int ss): x(xx) ,step(ss){}
};


int n, k;
bool vis[maxn + 10];
int dir[2] = {1, -1};

bool test(int x)
{
    if (x >= 0 && x <= maxn && vis[x] == 0)
        return 1;
    return 0;
}

void bfs(int x, int step)
{
    queue <node> q;
    q.push(node(x, step));
    vis[x] = 1;
    while (!q.empty())
    {
        node top = q.front();
        if (top.x == k)
        {
            printf("%d\n", top.step);
            return;
        }

        q.pop();
        for (int i = 0; i < 2; i++)
        {
            if (test(top.x + dir[i]))
            {
                q.push(node(top.x + dir[i], top.step + 1));
                vis[top.x + dir[i]] = 1;
            }

        }
        if (test(top.x * 2))
        {
            q.push(node(top.x * 2, top.step + 1));
            vis[top.x * 2] = 1;
        }
    }
}

void solve()
{
    scanf("%d%d", &n, &k);
    memset(vis,0,sizeof(vis));
    if (k <= n)
    {
        printf("%d\n", n - k);
        return ;
    }

    bfs(n, 0);

}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

