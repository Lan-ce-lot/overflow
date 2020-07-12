/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;

ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}

ll t, x, y ,z;
char a[maxn], b[maxn], c[maxn];
void Add(char str1[],char str2[])
{
	int len1,len2,i,j;
	int a[maxn],b[maxn];
	len1 = strlen(str1);
	len2 = strlen(str2);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=len1-1, j=0; i>=0; i--)
		a[j++]=str1[i]-'0';
	for(i=len2-1, j=0; i>=0; i--)
		b[j++]=str2[i]-'0';
	for(i=0; i<maxn; i++)
	{
		a[i] += b[i];
		if(a[i] > 9)
		{
			a[i] -= 10;
			a[i+1]++;
		}
	}
	for(i=maxn-1; (i>=0)&&(a[i]==0); i--);
	if(i>=0)
		for(; i>=0; i--)
			printf("%d",a[i]);
	else
		printf("0");
	printf("\n");
}

int main()
{
    t = read();
    while (t--)
    {
        scanf("%s %s %s", &a, &b, &c);
//        for ()
//        {
//
//        }
        printf("%s %s %s\n", a, b, c);
        printf(t?"%lld%lld%lld\n":"-1\n", x, y, z);
    }
    return 0;
}
