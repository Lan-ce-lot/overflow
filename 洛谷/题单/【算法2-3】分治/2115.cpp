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
#include <map>
#include <set>
typedef long long ll;
long long p=0;
long long qu(long long x,long long y)
{
    if(y==0)
    {
        return 1;
    }
    else
    {
        long long dq=qu(x,y/2);
        if(y%2==0)
        {
            return ((dq%p)*(dq%p))%p;
        }
        else if(y%2==1)
        {
            return ((dq%p)*(dq%p)*(x%p))%p;
        }
    }
}
ll qpow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (x & 1)  res *= x, res %= p;
		x *= x, x %= p;
		n >>= 1;
	}
	return res;
} 
int main()
{
    long long m=0,n=0;
    scanf("%lld %lld",&m,&n);
    printf("%lld\n", qpow(m,n));
    p=100003;
    printf("%lld",(qpow(m,n)-(m*qpow(m-1,n-1))%p+p)%p);
    return 0;
}
