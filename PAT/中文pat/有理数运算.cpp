#include <bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2,a_0,b_0,flag=0;
string str="+-*/=";
void f1(int a,int b)
{
	int g=__gcd(abs(a),abs(b));
	a/=g;
	b/=g;
	if(a>b)
	{
		if(a%b)
	{
		int count=a/b;
		int temp=a%b;
		a>=0?printf("%d %d/%d",count,temp,b):printf("(%d %d/%d)",count,temp,b);
	}
	else
	{
		a>=0?printf("%d ",a/b):printf("(%d)",a/b);
	}	
			
	}
	if(a<=b)
	{
		if(a%b)
	{
		
		a>=0?printf("%d/%d",a,b):printf("(%d/%d)",a,b);
	}
	else
	{
		a>=0?printf("%d",a/b):printf("(%d)",a/b);
	}
	}
}

void fadd(int a1,int b1,int a2,int b2)//jiafenshu
{
	int A,B,count=0,temp=0;
	(a1*b2+a2*b1)>=0?flag=1:flag=0;
	temp=__gcd(abs(a1*b2+a2*b1),b1*b2);
	A=abs((a1*b2+a2*b1)/temp);
	B=abs(b1*b2/temp);
	if(B==0)
	{
		printf("Inf");
		return;
	}
	if(A==0)
	{
		printf("0");
		return;
	}
	count=A/B;
	temp=A%B;
	if(count)
	{
		
		if(temp)
		{
			flag?printf("%d %d/%d",count,temp,B):printf("(-%d %d/%d)",count,temp,B);
		}
		else
		{
			flag?printf("%d",A/B):printf("(-%d)",A/B);
		}
	}
	else
	{
		flag?printf("%d/%d",temp,B):printf("(-%d/%d)",temp,B);
	}
}
void fsub(int a1,int b1,int a2,int b2)
{
	int A,B,count=0,temp=0;
	(a1*b2-a2*b1)>=0?flag=1:flag=0;
	temp=__gcd(abs(a1*b2-a2*b1),b1*b2);
	A=abs((a1*b2-a2*b1)/temp);
	B=abs(b1*b2/temp);
	if(B==0)
	{
		printf("Inf");
		return;
	}
	if(A==0)
	{
		printf("0");
		return;
	}
		count=A/B;
	temp=A%B;
	if(count)
	{
		
		if(temp)
		{
			flag?printf("%d %d/%d",count,temp,B):printf("(-%d %d/%d)",count,temp,B);
		}
		else
		{
			flag?printf("%d",A/B):printf("(-%d)",A/B);
		}
	}
	else
	{
		flag?printf("%d/%d",temp,B):printf("(-%d/%d)",temp,B);
	}
}
void fmul(int a1,int b1,int a2,int b2)
{
	int A,B,count=0,temp=0;
	(a1*a2)>=0?flag=1:flag=0;
	temp=__gcd(abs(a1*a2),b1*b2);
		A=abs((a1*a2)/temp);
	B=abs(b1*b2/temp);
	if(B==0)
	{
		printf("Inf");
		return;
	}
	if(A==0)
	{
		printf("0");
		return;
	}
		count=A/B;
	temp=A%B;
	if(count)
	{
		
		if(temp)
		{
			flag?printf("%d %d/%d",count,temp,B):printf("(-%d %d/%d)",count,temp,B);
		}
		else
		{
			flag?printf("%d",A/B):printf("(-%d)",A/B);
		}
	}
	else
	{
		flag?printf("%d/%d",temp,B):printf("(-%d/%d)",temp,B);
	}
}
void fdiv(int a1,int b1,int a2,int b2)
{
	int A,B,count=0,temp=0;
	(a1*b2)*(a2*b1)>=0?flag=1:flag=0;
	temp=__gcd(abs(a1*b2),abs(b1*a2));
		A=abs((a1*b2)/temp);
	B=abs(b1*a2/temp);
	if(B==0)
	{
		printf("Inf");
		return;
	}
	if(A==0)
	{
		printf("0");
		return;
	}
		count=A/B;
	temp=A%B;
	if(count)
	{
		
		if(temp)
		{
			flag?printf("%d %d/%d",count,temp,B):printf("(-%d %d/%d)",count,temp,B);
		}
		else
		{
			flag?printf("%d",A/B):printf("(-%d)",A/B);
		}
	}
	else
	{
		flag?printf("%d/%d",temp,B):printf("(-%d/%d)",temp,B);
	}
}


int main()
{
	char c;
	scanf("%d%c%d%d%c%d",&a1,&c,&b1,&a2,&c,&b2);
	for(int i=0;i<4;i++)
	{
	f1(a1,b1);
	cout<<' '<<str[i]<<' ';
	f1(a2,b2);
	cout<<' '<<str[4]<<' ';
	if(i==0)fadd(a1,b1,a2,b2);
	if(i==1)fsub(a1,b1,a2,b2);
	if(i==2)fmul(a1,b1,a2,b2);
	if(i==3)fdiv(a1,b1,a2,b2);	
	puts("");	
	}
    return 0;
}
