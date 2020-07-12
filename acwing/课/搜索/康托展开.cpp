/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:

* 简述
康托展开是一个全排列到一个自然数的双射，常用于构建hash表时的空间压缩。
设有n个数（1，2，3，4,…,n），可以有组成不同(n!种)的排列组合，康托展开
表示的就是是当前排列组合在n个不同元素的全排列中的名次。

* 原理
X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!

https://www.cnblogs.com/sky-stars/p/11216035.html
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

string str;
int maze[9];//目标

struct node1
{
    char way;
    int fath;
};

struct node2
{
    int aa[10];
    int n;//X的线性位置
    int son;
};

node1 Node[370000];//状态储存
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int FAC[10] =
{
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
};//阶乘打表

int cantor(int *a, int n)
{
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        int smaller = 0;  // 在当前位之后小于其的个数
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
                smaller++;
        }
        x += FAC[n - i - 1] * smaller; // 康托展开累加
    }
    return x;  // 康托展开值
}

void bfs(int a[])
{
    queue <node2> Q;
    node2 q, p;
    int e, tx, ty, tem, t = 0;
    for (e = 0; e < 9 ; e++)
    {
        q.aa[e] = a[e];
    }
    q.n = 8;
    q.son = 0;
    Node[q.son].fath = 0;
    Q.push(q);
    while (!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for (e = 0; e < 4; e ++)
        {
            p = q;
            tx = q.n % 3 + dir[e][0];//x坐标转换 + 移动
            ty = q.n / 3 + dir[e][1];//y坐标转换 + 移动
            if (tx >= 0 && ty >= 0 && tx < 3 && ty < 3)
            {
                p.n = ty * 3 + tx;
                tem = p.aa[p.n];
                p.aa[p.n] = p.aa[q.n];
                p.aa[q.n] = tem;
                p.son = cantor(p.aa, 9);//康托展开

                if (Node[p.son].fath == -1)//判重
                {
                    Node[p.son].fath = q.son;
                    if (e == 0)
                        Node[p.son].way = 'l';
                    if (e == 1)
                        Node[p.son].way = 'r';
                    if (e == 2)
                        Node[p.son].way = 'u';
                    if (e == 3)
                        Node[p.son].way = 'd';
                    Q.push(p);
                }
            }
        }
    }
}

void solve()
{
    int s;
    while (getline(cin, str))
    {
        for (int i = 0, j = 0; i < str.size(); i++)
        {
            if (str[i] == 'x')
            {
                maze[j++] = 9;
            }
            else if (str[i] >= '0' && str[i] <= '8')
            {
                maze[j++] = str[i] - '0';
            }
        }
        s = cantor(maze, 9);
        if (Node[s].fath == -1)
        {
            //printf("unsolvable\n");
            puts("-1");
            continue;
        }
        string str;
        while (s != 0)
        {
            //printf("%c", Node[s].way);
            str += Node[s].way;
            s = Node[s].fath;
        }
        cout << str.size() << endl;
    }
}
int a[10];
int t, n;
int main()
{
//    ios::sync_with_stdio(false);

    for(int i=0;i<9;i++)//目标
        a[i]=i+1;
    for(int i=0;i<370000;i++)
        Node[i].fath=-1;
    bfs(a);
    solve();
    return 0;
}

