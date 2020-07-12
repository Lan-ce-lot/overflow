#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
#define Mo 1000000007 
 
int main()
{
	int n,m,z;
	
	cin>>n>>m;
	vector<vector <int> > vi(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>vi[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			j==0?cout<<vi[j][i]<<endl:cout<<vi[j][i]<<' ';
		}
	}
	return 0;

}
