/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
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

char c;
int n, m, a, b;
int main()
{
    cin >> n >> m;
    ta.init_0();
    while (m-- )
    {
        cin >> c >> a >> b;
        if (c == 'x')
        {
            ta.add(a, b);
        }
        else
        {
            cout << ta.getsum(b) - ta.getsum(a - 1) << endl;
        }
    }
    return 0;
}

