/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 10007;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
const int inf=2147483647;
int num[105];
int numk[15];
int N;
int main()
{
	int m,k,n;
	int count,ans;
	scanf("%d",&m);
	while(m--)
	{
		memset(numk,0,sizeof(numk));
		count=0;
		ans=0;
		int flag;
		scanf("%d%d",&k,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=0;j<count;j++)
			{
				if(num[i]==numk[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				if(count<k)
				{
					numk[count++]=num[i];
					ans++;
					continue;
				}
				else
				{
					int temp=0;
					int Max=0;
					int Maxi=0;
					int mark;
					int index;
					for(int j=0;j<count;j++)
					{
						mark=0;
						for(int k=i+1;k<n;k++)
						{
							if(numk[j]==num[k])
							{
								mark=1;
								temp=k;
								index=j;
								break;
							}
						}
						if(mark==0)
						{
							numk[j]=num[i];
							ans++;
							break;
						}
						else
						{
							if(temp>Max)
							{
								Max=temp;
								Maxi=index;
							}
						}
					}
					if(mark==1)
					{
						numk[Maxi]=num[i];
						ans++;
					}
				}


			}

		}
		cout<<ans<<endl;



	 }


	return 0;
}
