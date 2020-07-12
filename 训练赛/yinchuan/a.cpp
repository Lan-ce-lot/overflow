#include<iostream>
#include<iomanip>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cstdio>
typedef long long ll;
using namespace std;
const int Max=1e6+10;
priority_queue<int> que;
ll n,p,q,m,ans=0, max1;

unsigned int SA,SB,SC;

stack <ll> s;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

void gen()
{
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for (int i = 1; i <= n; i++)
    {

        if (rng61() % (p + q) < p)
        {
            int x = rng61() % m + 1;
            if (!s.size())
                s.push(x);
            else if (x > s.top())
                s.push(x);
            else
                s.push(s.top());

        }
        else
        {
            if (!s.empty())
                s.pop();
            else
                continue;
        }
        if (!s.empty())
            ans ^= i * s.top();
    }
}

int main()
{
	int T;
	scanf("%d",&T);
    for (int i = 1; i <= T; i++)
    {
        while (!s.empty())
            s.pop();
        ans = 0;
        gen();
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
//2
//4 1 1 4 23333 66666 233333
//4 2 1 4 23333 66666 233333
