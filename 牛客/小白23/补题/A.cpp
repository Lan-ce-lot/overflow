/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define lowbit(a) a & -a
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;
//sacnf("%lf") printf("%f")

int t, n, m, a, b;
char maze[7][100005];
bool vis[100];
set<int> S;
void dfs(int a1, int tem)
{
	if (a1 >= a)
	{
		S.insert(tem);
//		cout << tem <<endl;
		return;
	}
	for (int i = a1; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(a1 + 1, tem + (1 << i));
			
			vis[i] = 0;
		}
	}
}

void solve()
{
	scanf("%d", &t);
	while (t--)
	{
		S.clear();
		map<int, int> M;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", maze[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (maze[i][j] == '*')
				{
					M[j] ++;
				}
			}
		}
		dfs(0, 0);
		int flag = 0;
		for (set<int>::iterator it = S.begin(); it != S.end(); it++)
		{
			int temp = M.size();
			map<int, int> MM = M; 
			int j = *(it);
			while (j)
			{
				int t0 = log(lowbit(j)) / log(2);
				for (int k = 0; k < m; k++)
				{
					if (maze[t0][k] == '*')
					{
						if (MM[k] > 0)
						{
							MM[k] --;
							if (MM[k] == 0) temp--;	
						}
					}

		
				}
				j -= lowbit(j);
			}
			if (b >= temp)
			{
				puts("yes");
				flag = 1;
				break;
				
			}
		}
		if (flag == 0)
		{
			puts("no");
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

