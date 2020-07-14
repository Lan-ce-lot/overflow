#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int a[100010];
int f[100010][30];
int n, m, L, R;
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
//O(nlogn)预处理：dp(i,j) = min{dp(i,j-1), dp(i+2^(j-1),j-1)}  
//n为数组a的元素个数，k为n的二进制位数 
void init()
{
	for(int i = 1; i <= n; i++)
		f[i][0] = a[i];
	
	int k = floor(log((double)n)/log(2.0)); 		//求n的二进制位数 

	for(int j = 1; j <= k; j++)
	{
		for(int i = n; i >= 1; i--)
			if(i+(1<<(j-1)) <= n)
				f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	}
}

//O(1)查询：返回区间[i,j]的最小值    
int RMQ(int i, int j)
{
    int k = floor(log((double)(j-i+1))/log(2.0));

    return max(f[i][k], f[j-(1<<k)+1][k]);    
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		a[i] = read();
	init();
	while(m--)
	{
		L = read();
		R = read();
		printf("%d\n", RMQ(L,R)); 
	}
	return 0;
}
