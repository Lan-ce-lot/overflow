#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
ll a[1000000];
int main()
{
	a[0]=1;
	for(int i=1,t=2;i<1000000;t++)
	{
		if(t&1&&t%3&&t%5&&t%7)
			continue;
		else
			a[i++]=t;
	}
	int n,i=0;
	while(~scanf("%d",&n))
	{
		i++;
		if(n==0)return 0;
        else
        {
            if(n%10==1&&n%100!=11)
                printf("The %dst humble number is %d.\n",n,humble_number[n]);
            else if(n%10==2&&n%100!=12)
                printf("The %dnd humble number is %d.\n",n,humble_number[n]);
            else if(n%10==3&&n%100!=13)
                printf("The %drd humble number is %d.\n",n,humble_number[n]);
            else
                printf("The %dth humble number is %d.\n",n,humble_number[n]);
        }
    }
														//The 1st humble number is 1. 
	return 0;

}
