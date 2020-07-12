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
};

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
            printf("unsolvable\n");
            // puts("-1");
            continue;
        }
        string str;
        while (s != 0)
        {
            //printf("%c", Node[s].way);
            str += Node[s].way;
            s = Node[s].fath;
        }
        cout << str << endl;
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

//========================================================
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int f(string state)
{
    int res = 0;
    for (int i = 0; i < state.size(); i ++ )
        if (state[i] != 'x')
        {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}

string bfs(string start)
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char op[4] = {'u', 'r', 'd', 'l'};

    string end = "12345678x";
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;

    heap.push({f(start), start});
    dist[start] = 0;

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        string state = t.second;

        if (state == end) break;

        int step = dist[state];
        int x, y;
        for (int i = 0; i < state.size(); i ++ )
            if (state[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
        string source = state;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(state[x * 3 + y], state[a * 3 + b]);
                if (!dist.count(state) || dist[state] > step + 1)
                {
                    dist[state] = step + 1;
                    prev[state] = {source, op[i]};
                    heap.push({dist[state] + f(state), state});
                }
                swap(state[x * 3 + y], state[a * 3 + b]);
            }
        }
    }

    string res;
    while (end != start)
    {
        res += prev[end].second;
        end = prev[end].first;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string g, c, seq;
    while (cin >> c)
    {
        g += c;
        if (c != "x") seq += c;
    }

    int t = 0;
    for (int i = 0; i < seq.size(); i ++ )
        for (int j = i + 1; j < seq.size(); j ++ )
            if (seq[i] > seq[j])
                t ++ ;

    if (t % 2) puts("unsolvable");
    else cout << bfs(g) << endl;

    return 0;
}
