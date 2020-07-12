#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int n;
	scanf("%d",&n);
	cin>>a;
	for(int i=1;i<n;i++)
	{
		if(a[0]>=a[i])
		{
			if(a.substr(i,n-i+1)+a.substr(0,i)<a)
			{
				puts("YES");
				return 0;
			}	
		}	
	}	
	puts("NO");
	return 0;
}
