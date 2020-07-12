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
const int maxn=5005;
int x[maxn],y[maxn];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int line[4]={1,1,1,1};//1/3,1,-1,0
int a[maxn];
int main()
{
	int n,ans=0,ansl=0,count1=0,count13=0,count_1=0,count0=0,count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	for(int i=0;i<n;i++)//1/3,1,-1,0
	{
		for(int j=i+1;j<n;j++)
		{
			if(x[i]-x[j]==3*(y[i]-y[j]))//1/3
			{
				for(int z=0;z<4;z++)
				{
					if(z==0)continue;
					if(line[z])
					{
						ans++;
						line[z]--;
						break;
					}
				}	
			}
			
			
			else if(x[i]-x[j]==y[i]-y[j])//1
			{
				for(int z=0;z<4;z++)
				{
					if(z==1)continue;
					if(line[z]);
					{
						ans++;
						line[z]--;
						break;
					}
				}				
			}
			
			else if(x[i]-x[j]==y[j]-y[i])//-1
			{
				for(int z=0;z<4;z++)
				{
					if(z==2)continue;
					if(line[z])
					{
						ans++;
						line[z]--;
						break;
					}
				}				
			}
			
			else if(y[j]==y[i])//0
			{
				for(int z=0;z<4;z++)
				{
					if(z==3)continue;
					if(line[z])
					{
						ans++;
						line[z]--;
						break;
					}
				}				
			}
			else
			{
				count++;
			}			
			
		}
		
	}
	if(ans+count>=4)
	{
		cout<<4<<endl;
		return 0;
	}
    cout<<ans<<endl;
    return 0;
}
