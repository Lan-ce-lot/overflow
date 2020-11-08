#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 50000 + 5;
vector<P> ap, bp; 
ll mod = 998244353;
ll pw(ll a, ll b)
{
	ll ans = 1;
	while (b){
		if (b & 1)
			ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
ll od, p[N], com[N][4], cnum, ans = 1, dif;
bool prime[N];
void init(){
    for(int i = 2; i < N; i++) prime[i] = true;
    for(int i = 2; i < sqrt(N); i++){//判断改成i*i<N 
        if(prime[i]){
        	p[od++] = i;
            for(int j = i * i; j < N; j += i){//从i*i开始就可以了 
                prime[j] = false;  
            }
        }
    }
}
ll a, b, c, d, x, y;
int main()
{
	init();
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &x, &y);
	for (int i = 0; i < od; i++)
	{
		if (x == 1)	break;
		int sum = 0;
		if (x % p[i] == 0)
		{
			while (x % p[i] == 0){
				sum++;
				x /= p[i];
			}
			ap.push_back(P(p[i], sum));
		}
	}
	if (x != 1)
		ap.push_back(P(x, 1));
	for (int i = 0; i < od; i++)
	{
		if (y == 1)	break;
		int sum = 0;
		if (y % p[i] == 0)
		{
			while (y % p[i] == 0){
				sum++;
				y /= p[i];
			}
			bp.push_back(P(p[i], sum));
		}
	}
	if (y != 1)
		bp.push_back(P(y, 1));
	for (int i = 0; i < ap.size(); i++)
	{
	
		for (int j = 0; j < bp.size(); j++)
		{
			if (ap[i].first == bp[j].first)
			{
				com[cnum][0] = ap[i].first;
				com[cnum][1] = ap[i].second;
				com[cnum][2] = bp[j].second;
				cnum++;
			}
		}
	}
	if (!cnum)
	{
		printf("%lld\n", 1);
		return 0;
	}
	for (int k = 0; k < cnum; k++)
	{
		ll sum = 0;
		for (int i = a; i <= b; i++)
		{
			if (com[k][1] * i <= com[k][2] * c)
			{
				sum += com[k][1] * i * (d - c + 1);
			}
			else if (com[k][1] * i >= com[k][2] * d)
			{
				sum += (com[k][2] * c + com[k][2] * d) * (d - c + 1) / 2;
			}
			else
			{
				int inte = com[k][1] * i / com[k][2];
				if (com[k][1] * i > com[k][2] * inte)
					inte++;
				sum += com[k][1] * i * (d - inte + 1);
				sum += (com[k][2] * c + com[k][2] * (inte - 1)) * (inte - c) / 2;
			}
		}
		com[k][3] = sum;
	}
	for (int i = 0; i < cnum; i++)
	{
		ans = (ans * pw(com[i][0], com[i][3])) % mod;
	}
	printf("%lld\n", ans % mod);
}

