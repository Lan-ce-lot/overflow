#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=1005;
ll gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
 } 

ll lcm(int a,int b)
{
	return a*b/__gcd(a,b);
}

//ll gcd(ll a,ll b)
//{
//    ll t;
//    while(b)///当b为0时,得出结果,a既为结果
//    {
//        t=b;///存b
//        b=(a%b);///b为a对b取模
//        a=t;///a为上一次的b
//    }
//    return a;
//}

int a[maxn];
int main()
{
	cout<<gcd(2,2)<<lcm(2,2);
    
    return 0;
}
