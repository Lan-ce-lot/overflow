#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
bool w[500000];
int cnt;
int plist[10000],pcount=0;
int prime(int n)
{
	int i;
	if((n!=2 && !(n%2)) || (n!=3 && !(n%3)) || (n!=5 && !(n%5)) || (n!=7 && !(n%7)))
		return 0;
	for(i=0;plist[i]*plist[i]<=n;++i)
		if(!(n%plist[i]))
			return 0;
	return n>1;
}
void initprime()
{
	int i;
	for(plist[pcount++]=2,i=3;i<50000;++i)
		if(prime(i))
			plist[pcount++]=i;
}
int Div( int m )   //这段代码是核心，估计需要的是公式规律，还没琢磨透（来源于网络）
{
    int tmp,ret=1;
    for( int i=0; plist[i]*plist[i]<=m ; i++ )
    {
        if( m % plist[i] == 0 )
        {
            tmp = 0;
            while( m % plist[i] == 0 )
            {
                tmp ++;
                m /= plist[i];
            }
            ret = ret * ( tmp+1 );
        }
    }
    if( m != 1 )
        ret = ret * 2;
    return ret;
}
 
long long power_mod(long long a, long long b, long long c) {
    long long ans = 1;
    a %= c;
    while (b) {
        if (b & 1) {
            ans = ans * a % c;
        }
        b >>= 1;
        a = a * a % c;
    }
    return ans;
}
int main() {
    long long fac[1000] = {1}, n, m, p = 10007, k;
    for (int j = 1; j < 1000; j++) {
        fac[j] = fac[j-1] * j % p;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> m;
        cout << fac[n] * power_mod(fac[m], p-2, p) % p * power_mod(fac[n-m], p-2, p) % p << endl;
    }
}
