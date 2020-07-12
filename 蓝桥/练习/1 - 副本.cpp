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
int f(int a)
{
	return a*(a+1)/2;
}
int main()

{
	int a=1,sum=0;
	for(int i=1;i<=100;i++) 
	{
		sum+=f(i);
		
	}
	cout<<sum;


	return 0;

}
