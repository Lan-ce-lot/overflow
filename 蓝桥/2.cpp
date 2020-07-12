#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int main()
{
	char str[4][10][10]={{" ","I","II","III","IV","V","VI","VII","VIII","IX"},
						 {" ","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
						 {" ","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
						 {" ","M","MM","MMM"}},ch[15],ct[10];
	int t,i=0,j,k=0,r,len,sum,flag=0,s=0;
	cin>>ch;
	len = strlen(ch);
	for (i=0; i<len; i++)
	{
		k=0;
		for (j=i; j<=i+3; j++)
		{
			ct[k++]=ch[j];
		}
		ct[k]='\0';
		while (1)
		{
			sum=0;
			flag=0;
			for (j=0; j<4; j++)
			{
				for (r=1; r<10; r++)
				{
					if (strcmp(str[j][r],ct)==0) 
					{
						sum = pow(10,j);
						if (sum==1)
						 sum=0;
						if (j==0)
						 sum+=r;
						if (j!=0)
						 sum*=r;
						flag=1;
						j=5;
						s+=sum;
						sum=0;
						break;
					}
				}
			}
			if (flag)
			 break;
			ct[--k]='\0';
		}
		i=i+(k-1);
	}
	cout<<s;
	return 0;
}

