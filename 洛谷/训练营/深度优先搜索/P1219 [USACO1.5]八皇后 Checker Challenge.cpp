#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
typedef pair<int, int> PII;
const int maxn = 1e6 + 5;
int n, cnt = 0;
char maze[1005][1005];
bool c[maxn], l1[maxn], l2[maxn];
vector<PII> G;
void dfs(int x)
{
	if (x == n + 1)
	{
//		if (cnt == 3)
//			return cnt;
		cnt++;
		if (cnt <= 3)
		{
			for (int i = 0; i < G.size(); i++)
				cout << G[i]. second << (i == G.size() - 1 ? '\n' : ' ');
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!c[i] && !l1[i + x] && !l2[n - x + i])
		{
			c[i] = l1[i + x] = l2[n - x + i] = 1;
			G.push_back({x, i});
			maze[x][i] = 'Q';
			dfs(x + 1);
			G.pop_back();
			maze[x][i] = '.';
			c[i] = l1[i + x] = l2[n - x + i] = 0;
		}
	}
}

int main()
{
	cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            maze[i][j] = '.';
        }
    }
    
	dfs(1);
	cout << cnt << endl;

	return 0;
}
