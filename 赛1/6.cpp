#include<bits/stdc++.h> 

using namespace std;
char a[100][3]; 
int b[100],c[100],bb[100];
void cha(int *p,int a,int i)
{
	int temp=*p;
	*p=a; 
	for(;i>0;i--)
	{
		*(p+i)=*(p+i-1);
	}
	*(p+1)=temp;
}
int main()
{
	int n;
	int z=0;
	while(~scanf("%s",&a[z]))
	{
		if(a[z][0]>='0'&&a[z][0]<='9')
		{
			if(strlen(a[z])==2)
			{
				b[z]=10;
			}
			else
			{
				b[z]=a[z][0]-'0';
			}
		}
		else
		{
			if(a[z][0]=='J')
			b[z]=11;
			if(a[z][0]=='Q')
			b[z]=12;
			if(a[z][0]=='K')
			b[z]=13;
		}
		c[z]=b[z]-z-1;
		z++;
	}
	if(z<52)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<z;i++)
	{	
		
		if(c[i]<0)
		{
		
			cha(bb+b[i],b[i],i);

		}
		else
		{
			bb[i]=b[i];
		}
			
	}
		
	for(int i=0;i<z;i++)
	{
		if(bb[i]>=1&&bb[i]<=10)
		{
			i==0?printf("%d",bb[i]):printf(" %d",bb[i]);
		}
		else
		{
			if(bb[i]==11)
				i==0?printf("J"):printf(" J");
			if(bb[i]==12)
				i==0?printf("Q"):printf(" Q");
			if(bb[i]==13)
				i==0?printf("K"):printf(" K");
		}
	}	
	return 0;
}
