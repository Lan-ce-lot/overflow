
#include<bits/stdc++.h>
using namespace std;
int mod,k;
int power(int p,int k)
{
	int ans=1,t=1;
	while(k)
	{
		if(t==1)t=p;else t=t*t;
		if(k%2==1)ans=ans*t;
		k>>=1;
	}
	return ans;
}
int main()
{
    scanf("%d%d",&k,&mod);
    if(k>26)printf("%d",mod);else
        printf("%d",mod%power(2,k));
    return 0;
}
