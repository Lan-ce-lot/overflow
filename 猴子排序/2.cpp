#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#define e 2.71828182
#define PI 3.141592654
#define max(a,b)    (a>b?a:b)
#define min(a,b)    (a>b?b:a)
#define mem(a,b)    memset(a,b,sizeof(a))
#define _max(a,b,c) (max(a,b)>c?max(a,b):c)
#define mod 1000000007
using namespace std;
int a, b, c[10005], i;
int main()
{
	while (~scanf("%d%d", &a, &b)) 
	{
		//printf("%d\n", a + b);
		c[i++] = a + b;
	}
	for (int j = 0; j < i - 1; j++)
		cout << c[j] << endl;
	cout << c[i - 1];
	//cout << 1 << endl; 
}
