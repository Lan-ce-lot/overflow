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
void holl_triangle(int n,char c)
{
    for (int i=0; i<n;i++)
    {
        if(i!=n-1)
            for (int j=0; j<n+i; j++)
                if(j==n-i-1||j==n+i-1)
                    printf("%c",c);
                else
                    printf(" ");
        else
            for(int j=0; j<2*n-1; j++)
                printf("%c",c);
		 printf("\n");
    }
}

int main()
{
	int n,flag=0;
	char c;
	while(cin>>c&&c!='@'&&cin>>n)
	{
		
		if(flag>0)cout<<endl;
		holl_triangle(n,c);
		flag++;
	}	
	return 0;
}
