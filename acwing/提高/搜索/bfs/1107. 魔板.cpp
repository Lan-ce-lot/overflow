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
#include <unordered_map>
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
unordered_map<string, int> dis;
unordered_map<string, bool> vis;
unordered_map<string, pair<string, char> > M;
int maze[10];

string st = "12345678";
string end1 = "";
char g[2][4];
string get() {
    string s;
    for (int i = 0; i < 4; i++) s += g[0][i];
    for (int i = 3; i >= 0; i--) s += g[1][i];
    return s;
}

void seet(string s) {
    for (int i = 0; i < 4; i ++) g[0][i] = s[i];
    for (int i = 7, j = 0; j < 4; i--, j++) g[1][j] = s[i];
}

string move1(string s) {
    seet(s);
    for (int i = 0; i < 4; i++) swap(g[0][i], g[1][i]);
    return get();
}

string move2(string s) {
    seet(s);
    char temp1 = g[0][3];
    char temp2 = g[1][3];
    for (int i = 2; i >= 0; i--) {
        g[1][i + 1] = g[1][i];
        g[0][i + 1] = g[0][i];
    }
    g[0][0] = temp1;
    g[1][0] = temp2;
    return get();
}

string move3(string s) {
    seet(s);
    char temp = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = temp;
    return get();
}


int bfs() {
    queue<string> Q;
    Q.push(st);
    dis[st] = 0;

    while (!Q.empty()) {
        string top = Q.front();
        Q.pop();
        if (top == end1) {
//            debug(11);
            return dis[end1];
        }

        string m[3];
        m[0] = move1(top);
        m[1] = move2(top);
        m[2] = move3(top);
//        for (int i = 0; i < 3; i++) cout << m[i] << endl;
        for (int i = 0; i < 3; i++) {
            if (!dis.count(m[i])) {
                dis[m[i]] = dis[top] + 1;
                M[m[i]] = {top, 'A' + i};
                Q.push(m[i]);
                if (m[i] == end1) return dis[m[i]];
            }
        }
    }
    return -1;
}


void print(string s) {
    if (s == st) return;

    print(M[s].first);printf("%c", M[s].second);
}

void solve()
{
    for (int i = 0; i < 8; i++) {
        scanf("%d", &maze[i]);end1 += char(maze[i] + '0');
    }

    cout << bfs() << endl;
    print(end1);
//    puts("");

//    cout << st << endl;



}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

