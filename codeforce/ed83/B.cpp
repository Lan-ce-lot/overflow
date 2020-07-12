/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
ll t, n, k, a[maxn], counter = 0, tem[maxn];
map<ll, bool> vis;

bool pd(ll a)
{
	for (int i = 0; i < counter; i++)
	{
		if (a == tem[i])return 1;
	}
	return 0;
}

bool test(ll a, ll k)
{
	ll t_k = 0;
	vector<ll> t_1;
	
	for (int i = 0; i < 100; i++)
	{
		if (a == 1)
		{
			break;
		}
		if (pd(a))
		{
			
			break;
		}
		if (a % k)
		{
			a--;
			t_1.push_back(i);
		}
		if (pd(a))
		{
			
			break;
		}
		if (a % k)
		{
			return 0;
		}
		a /= k;
		t_k++;
	
	}
	ll b = a * pow(k, t_k);
//	if (b == 0) return 0;
//	cout << a << endl;
//	debug(b);
	if (vis[b])
	{
		return 0;
	}
	else
	{
		vis[b] = 1;
	}
	vis[int(a * pow(k, t_k))] = 1;
	for (int i = 0; i < t_1.size(); i++)
	{
		ll tt = ll(pow(k, t_1[i]));
		if (vis[tt])
		{
			return 0;
		}
		else
		{
			vis[tt] = 1;
		}
	}
	return 1;
	
}


void solve()
{
	cin >> t;
while (t--)
{
//	ff = 0;
//	sum = 0;
	cin >> n >> k;
	counter = 1;
	vis.clear();
	int flag = 0;
	tem[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for (int i = 1; i < 64; i++, counter++)
	{
		if (tem[i - 1]  > a[0] / k)
		{
			break;
		}
		
		else
		{
			tem[i] = tem[i - 1] * k;
//			cout << tem[i] << ' ';
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		continue;
		if (a[i] == 1)
		{
			if (vis[1])
			{
			cout << "NO" << endl;
			flag = 1;
			break;
			}
			else
			{
				vis[1] = 1;
			}
		}
		else if (!test(a[i], k))
		{
//			debug(a[i]); 
			cout << "NO" << endl;
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		cout << "YES" << endl;
		
	}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
1
2 2
1024 3072

*/

//=========================================
//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define pb push_back
//#define mp make_pair
//#define all(v) v.begin(),v.end()
//typedef long long ll;
//#define lim 1000000000000000001
// 
// 
//ll root(ll x,vector<ll>&v)
//{
//    while(v[x]!=x)
//    {
//        v[x]=v[v[x]];
//        x=v[x];
//    }
//    return x;
//}
// 
// 
// 
//int main()
//{
//     fast;
//    ll t;
//    // t=1;
//    cin>>t;
//    while(t--)
//    {
//        ll n,k;
//        cin>>n>>k;
//        vector<ll>v(n);
//        for(auto &x:v)cin>>x;
//        sort(all(v));
// 
//        vector<ll>tmp(60,0);
//        for(int i=0;i<n;i++)
//        {
//            ll a=v[i];
//            ll x=0;
//            while(a>0)
//            {
//                tmp[x]+=a%k;
//                a=a/k;
//                x++;
//            }
//        }
//        if(*max_element(tmp.begin(),tmp.end())<2)
//        cout<<"YES\n";
//        else
//        cout<<"NO\n";
// 
// 
//        
// 
//    }
//    return 0;
//}
