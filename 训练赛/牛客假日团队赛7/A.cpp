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
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


int main()
{
    ll a,temp1=0,temp2=0,b,ans=0;
    cin>>a>>b;
    	
    	while(a)
    	{
    		temp1+=a%10;
    		a/=10;
		}
    	
    	while(b)
    	{
    		temp2+=b%10;
    		b/=10;
		}
		cout<<temp1*temp2<<endl;
    return 0;
}
