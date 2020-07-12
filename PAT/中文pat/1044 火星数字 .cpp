#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
char strl[13][5]={"tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char strh[13][5]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char in[20];
stack<int> temp;
int inH=0,inL=0,inF=0;
const int INF=0x3f3f3f3f;
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		inH=0,inL=0,inF=0;
		
		fgets (in, 100, stdin);
//		gets(in);
		int lenth=0;
		for(int i=0;i<10;i++)
		{
			if(!in[i])
			{
				lenth=i;
				break;
			}
		}
		if(in[0]>='a')
		{
			if(lenth>5)//hight
			{
				
				for(int i=0;i<13;i++)
				{
					if(strncmp(strh[i],in,3)==0)
					{
						inH=i;
						inF=inH*13;
						
					}	
				}
				for(int i=0;i<13;i++)
				{
					if(strncmp(strl[i],in+4,3)==0)
					{
						inL=i;
						inF+=i;
						
						
					}	
				}
				printf("%d\n",inF);				
					
			}
			else
			{
				
				int flag=0;
				
				for(int i=0;i<13;i++)
				{
					if(strncmp(strl[i],in,3)==0)
					{
						inF=i;
						printf("%d\n",inF);
						flag=1;
						break;
					}
				}
				if(flag==0)
				for(int i=0;i<13;i++)
				{
					if(strncmp(strh[i],in,3)==0)
					{
						inF=i;
						printf("%d\n",inF*13);
						break;
					}
				}
				
			 } 

		
		}
		
		
		
		else
		{
			for(int i=0;i<3;i++)
			{
				if(in[i]>='0'&&in[i]<='9')
				{
					inF*=10;
					inF+=(in[i]-'0');
					
				}
				
			}
			if(inF%13==0)
			{
				printf("%s\n",strh[inF/13]);
				
			}
			else
			{
				int count=0;
			while(inF)
			{
				temp.push(inF%13);
				inF/=13;
				count++;				
			}
			if(count>1)
			{
				printf("%s ",strh[temp.top()]);
				temp.pop();
				printf("%s\n",strl[temp.top()]);	
				
			}
			else
			{
				printf("%s\n",strl[temp.top()]);
			}
			
			
			}
			
			
		}
		
		
	}
	
	
	return 0;

}
