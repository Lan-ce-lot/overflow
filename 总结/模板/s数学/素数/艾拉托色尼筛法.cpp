/*************************************************************************
 > File Name:
 > Author:  huangchangsheng
 > Mail:
 > Time:    19-7-07
 > Desc:    °£À­ÍÐÉ«ÄáÉ¸·¨ 
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
const int maxn = 1e14 + 5;//lim
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

bool isprime[maxn];
int prime[maxn], nprime;
void doprime()
{
    ll i, j;
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (isprime[i])
        {
            prime[++nprime] = i;
            for (int j = i * i; j < maxn; j += i)
            {
                isprime[j] = false;
            }
        }
    }

}


int a[maxn];
int main()
{
    doprime();
//    for(int i = 1; i < maxn && prime[i] != 0; i++)
//    {
//        cout << prime[i] << endl;
//
//    }

    return 0;
}
