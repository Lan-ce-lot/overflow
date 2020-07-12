#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll n,a[101];
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t=0;
		scanf("%d",&t);
		a[t]++;
	 } 
	int q,s;
	 scanf("%d",&q); 

	for(int i=0;i<q;i++)
	{
		scanf("%d",&s);
		i==0?printf("%d",a[s]):printf(" %d",a[s]);
	}
    return 0;
}
