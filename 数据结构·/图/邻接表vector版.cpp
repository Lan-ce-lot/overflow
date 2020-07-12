/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

struct Node
{
    int v,w;
    Node(int _v, int _w) : v(_v), w(_w){}
};

vector<Node> Adj[maxn];

int main()
{
//    ios::sync_with_stdio(false);
    Adj[0].push_back(Node(1, 2));
    Adj[0].push_back(Node(4, 1));
    Adj[1].push_back(Node(0, 2));
    Adj[1].push_back(Node(2, 2));
    Adj[1].push_back(Node(4, 2));
    Adj[2].push_back(Node(1, 2));
    Adj[2].push_back(Node(3, 1));
    Adj[3].push_back(Node(2, 1));
    Adj[3].push_back(Node(4, 1));
    Adj[4].push_back(Node(0, 1));
    Adj[4].push_back(Node(1, 2));
    Adj[4].push_back(Node(3, 1));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < Adj[i].size(); j++)
        {
            cout << "head:" << i << " ->" << Adj[i][j].v;
            j == Adj[i].size() - 1 ? cout << endl : cout << "->";
        }
    }
    return 0;
}
