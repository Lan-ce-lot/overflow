/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

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
int t, n;
vector<int> son[maxn];
int f[maxn];
int j, o;
ll ans = 0;
int ff[maxn];

bool vis[maxn];
void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> f[i];
        //f[i] = read();
        vis[i] = !vis[f[i]];
       // son[f[i]].push_back(i);
    }
    j = o = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            o++;
        }
        else
        {
            j++;
        }
    }
    ans = ((ll)j * (j - 1)) + (o * (ll)(o - 1));
    cout << ans << endl;

}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}
//==============================================================
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<cstdlib>
//#include<cctype>
//#include<ctime>
//#include<iostream>
//#include<string>
//#include<map>
//#include<queue>
//#include<stack>
//#include<set>
//#include<vector>
//#include<iomanip>
//#include<list>
//#include<bitset>
//#include<sstream>
//#include<fstream>
//#include<complex>
//#include<algorithm>
//#if __cplusplus >= 201103L
//#include <unordered_map>
//#include <unordered_set>
//#endif
//#define ll long long
//#define int long long
//using namespace std;
//const int INF = 0x3f3f3f3f;
//bool vis[1000005];
//int a[1000005];
//int main(){
//	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	int n;
//	cin>>n;
//	//vis[1]=0;
//	for(int i=2;i<=n;i++){
//		cin>>a[i];
//		vis[i]=!vis[a[i]];
//	}
//	int num1=0,num2=0;
//	for(int i=1;i<=n;i++){
//	//	cout<<vis[i]<<" "<<i<<endl;
//		if(vis[i]) num1++;
//		else num2++;
//	}
//	//cout<<num1<<" "<<num2<<endl;
//	cout<<(num1*(num1-1))+(num2*(num2-1))<<endl;
//    return 0;
//}


