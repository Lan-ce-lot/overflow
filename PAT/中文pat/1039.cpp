#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c[100005];
	scanf("%s",c);
	int l=strlen(c);
	long long numt,numat,numpat;
	numt=numat=numpat=0;
	for(int i=0;i<l;i++)
	{
		if(c[i]=='P')
			numt++;
		else if(c[i]=='A')
		{
			numat+=numt;
		}
		else 
		{
			numpat+=numat;
		}	
	}
	int t=1000000007;
	printf("%lld",numpat%t);
	return 0;
}
