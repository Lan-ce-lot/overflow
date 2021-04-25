#include <bits/stdc++.h>
#define inf 0x7fffffff
//#define ll long long
#define int long long
//#define double long double
#define eps 1e-8
//#define mod 1e9+7
using namespace std;
const int mod=1e9+7;
const int M=1e5;
const int N=1e3+5;//空间最大限制 4e8
int n,m;
int d[N][N];
struct node
{
	int pos,val;
};
vector < node > a;
map < int , int > mp;
int all = 0, anssum = 1e9 + 5, ans = 0;
signed main(){
//	ios::sync_with_stdio(false);
	int T;
	for(int i=0;i<N;i++)  for(int j=0;j<N;j++)  d[i][j]=1e9+5;
	for(int i=0;i<N;i++)  d[i][i]=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		d[x][y]=d[y][x]=min(d[x][y],z);
	}
	cin>>T;
	for(int index=1;index<=T;index++)
	{
		int x=0;
		int sum=0;
		int flag=0;
		mp.clear();
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			int y;
			scanf("%lld",&y);
			sum+=d[x][y];
			x=y;
			mp[y]++;
		}
		for(int i=1;i<=n;i++)  if(mp[i]!=1)  flag=1;
		sum+=d[x][0];
		if(sum<=1e9&&!flag)
		{
			all++;
			if (anssum > sum) {
				anssum = sum;
				ans = index;
			}
//			node t;
//			t.val=sum;
//			t.pos=index;
//			a.push_back(t);
		}
	}
//	sort(a.begin(),a.end(),cmp);
//	cout<<a.size()<<endl;
//	if(a.size()!=0)  cout<<a[0].pos<<" "<<a[0].val;
	cout << all << endl;
	cout << ans << ' ' << anssum << endl;
    return 0;
}	

