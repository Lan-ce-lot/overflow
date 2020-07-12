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
int main()

{
	int n,a[1000000],max;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	max=*max_element(a,a+i);
	max-25>0?printf("%d\n",max-25):printf("0\n"); 
	return 0;

}
