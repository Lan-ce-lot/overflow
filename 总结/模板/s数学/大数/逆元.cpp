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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

int exgcd(int a, int b, int& x, int& y)
{
	int d = a;
	if (b != 0)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}

int mod_inverse(int a, int b)
{
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;	
} 
int main()
{
    
    return 0;
}
