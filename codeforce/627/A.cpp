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
const int maxn=100005;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll a[maxn], t, n, tem, tte;
ll __lcm(ll a, ll b)
{
	return a * b / __gcd(a, b);
}

struct node
{
	int fr, to, i;
}E[maxn];
struct No
{
	int n, deep;
}NN[maxn];

bool cmp(No a, No b)
{
	return a.deep < b.deep;
}

vector<int> G[maxn];
int ans[maxn];
int main()//a * b < w
{
	
	
	cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
    	int a1, b1;
    	cin >> a1 >> b1;
    	E[i].fr = a1;
    	E[i].to = b1;
    	
    	NN[a1].deep++;
    	NN[a1].n = a1;
		NN[b1].deep++;
		NN[b1].n = b1;
		G[a1].push_back(i);
		G[b1].push_back(i);
	}
	
	sort(NN + 1, NN + n + 1, cmp);
	memset(ans, -1, sizeof ans);
	for (int i = 1, temp = 1; i <= n; i++)
	{
		for (int j = 0; j < G[NN[i].n].size(); j++)
		{
			if (ans[G[NN[i].n][j]] == -1)
			{
				ans[G[NN[i].n][j]] = temp - 1;
//				cout << '*' << NN[i].n << ' ' << G[NN[i].n][j] << ' ' << i - 1 << endl;
				temp++;
			 } 
		}
	}
//	cout << ' ';
	for (int i = 0; i <= n - 2; i++)
	{
		cout << ans[i] << endl;
	}
    return 0;
}
