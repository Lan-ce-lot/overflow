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

int a[maxn];
int main()
{
    string str;
    while (getline(cin, str))
    {
    	if (str == "ENDOFINPUT")
			return 0;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'F' && str[i] <= 'Z')
			{
				str[i] -= 5;
			}
			else if (str[i] >= 'A' && str[i] <= 'E')
			{
				str[i] += 21;
			}
		}
		cout << str <<endl;
		getline(cin, str);
	}
    
    return 0;
}
