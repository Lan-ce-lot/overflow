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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;
class TA
{
private:
    int e[maxn];
    int len;
    int lowbit(int k)
    {
        return k & (-k);
    }
public:
    void add(int x,int v)													//区间更新
    {
        while(x <= len)
            e[x] += v,x += lowbit(x);
    }
    void init(int* getin,int _len)											//初始化
    {
        len = _len;
        for(int i = 1; i <= len; i ++)
            add(i,*(getin + i - 1));
    }
    void init_0()
    {
        len = maxn,memset(e, 0, sizeof(e));
    }
    int getsum(int x)														//询问
    {
        int sum = 0;
        while(x > 0)
            sum += e[x],x -= lowbit(x);
        return sum;
    }
}ta;

typedef pair<int, int> P;
vector<int> vx, vy;
vector<P> t[maxn], ask[maxn];
int T, n, m, k;

struct line
{
    int x, y;
    char dir;
} a[maxn];

void LiSanhua(line a[], int k)
{

    vx.clear();
    vy.clear();
    for(int i = 1; i <= k; i++)
        vx.push_back(a[i].x), vy.push_back(a[i].y);//空格好评
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());//unique去重
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    n = vx.size() + 1;
    m = vy.size() + 1;
    for (int i = 1; i <= k; i++)
        a[i].x = lower_bound(vx.begin(), vx.end(), a[i].x) - vx.begin() + 1, a[i].y = lower_bound(vy.begin(), vy.end(), a[i].y) - vy.begin() + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        ll ans = 0;
        cin >> n >> m >> k;
        for (int i = 1 ; i  <=  k; i++)
            cin >> a[i].x >> a[i].y >> a[i].dir;
        //离散化函数
        LiSanhua(a, k);
        for (int i = 0; i <= max(n, m); i++)
            t[i].clear(), ask[i].clear();

        for (int i = 1; i <= k; i++)
            if (a[i].dir == 'U')
                t[a[i].y].push_back(make_pair(a[i].x, 1));
            else if (a[i].dir == 'D')
                t[1].push_back(make_pair(a[i].x, 1)), t[a[i].y + 1].push_back(make_pair(a[i].x, -1));
            else if (a[i].dir == 'R')
                ask[a[i].y].push_back(make_pair(a[i].x, n - 1));
            else
                ask[a[i].y].push_back(make_pair(1, a[i].x));

        //树状数组操作
        ta.init_0();
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0 ; j < t[i].size(); j++)
                ta.add(t[i][j].first, t[i][j].second);

            for (int j = 0; j < ask[i].size(); j++)
                ans += ta.getsum(ask[i][j].second) - ta.getsum(ask[i][j].first - 1);
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
