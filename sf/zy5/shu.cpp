#include <iostream>
using namespace std;
int find(int x) {
	return x==f[x]?x:f[x]=find(f[x]);
}
int f[100010],a,b,p,ans;
bool np[100010];
int main()
{
	int i,j;
	cin>>a>>b>>p;
	ans=b-a+1;
	for (i=a;i<=b;++i)
		f[i]=i;
	for (i=2;i<=b;++i)
		if (!np[i])
			if (i>=p)
				for (j=i*2;j<=b;j+=i)
				{
					np[j]=true;
					if (j-i>=a&&find(j)!=find(j-i))
						f[find(j)]=find(j-i), --ans;
				}
			else
				for (j=i*2;j<=b;j+=i)
					np[j]=true;	
	cout<<ans;
	return 0;
} 
