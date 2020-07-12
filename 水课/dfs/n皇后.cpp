#include <iostream>
using namespace std;
int n, s[9][9], num = 0, ans;
bool vis[100][2];
bool hang[100][2];
bool zheng[100][2];
bool fan[100][2];
void dfs(int idx)
{
    if(idx >= n) //结束条件
    {
        ans++;// 之前的搜索过程已经保证合法
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!hang[i][0] && !zheng[idx + i][0] && !fan[idx - i + n - 1][0] && s[idx][i] == 1)
        {
            hang[i][0] = true;
            zheng[idx + i][0] = true;
            fan[idx - i + n - 1][0] = true;
            for(int j = 0; j < n; j++)
            {
                if(i != j && !hang[j][1] && !zheng[idx + j][1] && !fan[idx - j + n - 1][1] && s[idx][j] == 1)
                {
                    // i!=j:不能放在用一个位置
                    hang[j][1] = true;
                    zheng[idx + j][1] = true;
                    fan[idx - j + n - 1][1] = true;
                    dfs(idx + 1);
                    hang[j][1] = false;
                    zheng[idx + j][1] = false;
                    fan[idx - j + n - 1][1] = false;
                }
            }
            hang[i][0] = false;
            zheng[idx + i][0] = false;
            fan[idx - i + n - 1][0] = false;
        }
    }
}
int main()
{
    cin >> n;
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}
