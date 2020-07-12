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
int main()
{
	string str="zailaiyihe",sb;
	int n,l=str.size(),flag=0;
	scanf("%d",&n);
	while(n--)
	{
		cin>>sb;
		int l1=sb.size();
		for(int i=0;i<l1;i++)
		{
			if(sb.substr(i,l)==str)
			{
				flag++;
				break;
			}
		
			
		}
		
	}
	printf("%d\n",flag);
	

//	system("pause");
	return 0;

}
