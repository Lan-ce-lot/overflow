/*************************************************************************
 > FileName:
 > Author:      huangchangsheng     
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
const __int128 mod = 1e35 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int a[maxn];

ll Q_mul(ll a, ll b)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}
ll jiec(ll n)
{
	ll ans = 1;
	for (int i = 2; i <= n; i++)
	{
		ans = Q_mul(ans, i) % mod;
	}
	return ans;
}
//__int128 ans = 1;
int n;
int main()
{
	ll n;
	while (cin >> n)
	{
		cout << jiec(n) << endl;
	}
    return 0;
}
//***超大数阶乘取模，20！封顶 
//void print(__int128 x)  
//{  
//    if(!x)  
//    {  
//        puts("0");  
//        return ;  
//    }  
//    string ret="";  
//    while(x)  
//    {  
//        ret+=x%10+'0';  
//        x/=10;  
//    }  
//    reverse(ret.begin(),ret.end());  
//    cout<<ret<<endl;  
//}  

//int main()
//{
//	while (cin >> n)
//	{
//		ans = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			ans = Q_mul(ans, i) % mod;
//		}
//		print(ans);
//	}
//    return 0;
//}
