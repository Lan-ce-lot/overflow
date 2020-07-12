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
const int maxn = 1e6 + 5;
int n;
ll t, ans = 0;
ll z[maxn];
char s[maxn];
void get_z()
{
    int l=0,r=0;
    for (int i=1;i<n;i++)
    {
        if (i>r)
        {
            l=i,r=i;
            while (r<n && s[r-l]==s[r]) r++;
            r==n?z[i]+=r-l-1,r--:z[i]+=r-l,r--;
        }
        else
        {
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else
            {
                l=i;
                while (r<n && s[r-l]==s[r]) r++;
				r==n?z[i]+=r-l-1,r--:z[i]+=r-l,r--;
            	
            }
        }
        ans += z[i];
    } 
}
int main()
{
    cin >> t;
    while(t--)
    {
    	memset(z,0,sizeof(z));
    	ans = 0;
        scanf("%s", s);
        n = strlen(s);
        get_z();
        cout << ans + n - 1<<endl;
    }
    return 0;
}
