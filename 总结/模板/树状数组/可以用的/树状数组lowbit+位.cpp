#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=500005;
int lowbit(int x)
{
	return x&-x;
}

int bit_1(int x)//计算一的个数 
{
	int num=0;
	while(x)
		x-=lowbit(x),num++;
	return num;
}

int main()
{
	int n;
	while(cin>>n)
		cout<<bit_1(n)<<endl;
    return 0;
}
