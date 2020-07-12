#include<bits/stdc++.h>
using namespace std;
#define ll long long
int room,t,num[100000];
int main()
{
	
	scanf("%d%d",&room,&t);
	for(int i = room;i > 0;i--)
	{
		num[i] = num[i+1]+1;
	}
	for(int i = 0;i < t;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp == 1)
		{
			int nu,flag=1;
			scanf("%d",&nu);
			for(int i = 1;i <= room;i++)
			{
				if(num[i] >= nu)
				{
					flag = 0;
					printf("%d\n",i);
					for(int k = i;k < i + nu;k++)
					{
						num[k] = 0;
					}
					break;
				}
			}
			if(flag)puts("0");
			
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i = l + r - 1;i >= 1;i--)
			{
				if(i < l && num[i] == 0)break;
				num[i] = num[i + 1] + 1;
			}
			
		}
	}
}
