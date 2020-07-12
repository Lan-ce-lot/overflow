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
const int maxn=5010;

int g[maxn][maxn];
int main()
{
    int n,r;
	cin>>n>>r;
	int a=r,b=r;
	for(int i=0,x,y,v;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		x++,y++;
		a=max(a,x),b=max(b,y);
		g[x][y]=+v;
		
	 } 
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	int res=0;
	for(int i=r;i<=a;i++)
		for(int j=r;j<=b;j++)
			res=max(res,g[i][j]-g[i][j-r]-g[i-r][j]+g[i-r][j-r]);
	cout<<res<<endl;
    return 0;
}
