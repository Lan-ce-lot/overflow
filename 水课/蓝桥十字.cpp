#include<iostream>
#include<cstring>
using namespace std;
char a[150][150],b[10];
int main()
{
	int n,t=2;
	scanf("%d",&n);
	int t1=4*n+4;
	memset(a,'.',sizeof(a));
	for(int i=0;i<2*n+2;i+=2,t+=2)//zs
	{
		a[t1-2-i][i+1]=a[t1-2-i][t1-i-1]=a[2+i][t1-i-1]=a[2+i][i+1]='$';//h
		a[i+1][t1-2-i]=a[t1-i-1][t1-2-i]=a[t1-i-1][2+i]=a[i+1][i+2]='$';//s
		a[t1-i-2][i+2]=a[i+2][t1-i-2]=a[t1-i-2][t1-i-2]=a[i+2][i+2]='$';
		for(int j=t;j<=2*n+2;j++)
		{
			a[i][t1-j]=a[t1-i][j]=a[t1-i][t1-j]=a[i][j]='$';//h
			a[j][t1-i]=a[t1-j][i]=a[t1-j][t1-i]=a[j][i]='$';//s
		}
	}
	for(int i=0;i<4*n+5;i++)
		for(int j=0;j<4*n+5;j++)
			j==4*n+4&&i!=4*n+4?printf("%c\n",a[i][j]):printf("%c",a[i][j]);
	return 0;
}
