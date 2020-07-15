// #include<iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<vector>

// using namespace std;

// int t, n, a[1005];

// int mex() {
//     int vis2[1005];
//     memset(vis2, 0, sizeof vis2);

//     for (int i = 0; i < n; i++) {
//         vis2[a[i]] ++;
//     }
//     for (int i = 0; i <= n; i++) {
//         if (vis2[i] == 0) return i;
//     }
//     return n;
// }


// int main() {
//     // cout << "Helloword" << endl;
//     // cout << "good night" << endl;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         for (int i = 0; i < n; i++) {
//             scanf("%d", &a[i]);
//         }

//         vector<int> ans;

//         while (n > 0) {
//             int me = mex();
//             if (me == n) {
//                 a[n - 1] = n;
//                 ans.push_back(n - 1);
//                 n--;
//             } else {
//                 a[me] = me;
//                 ans.push_back(me);
//             }
//         }
//         cout << ans.size() << endl;
//         for (auto i : ans) {
//             cout << i + 1 << ' ';
//         }
//         puts("");
//     }
//     return 0;
// }

#include<bits/stdc++.h>


using namespace std;
const int maxn = 150;


bool vis[maxn][maxn];
int stu[maxn][maxn];


int num[maxn];
int n, m, ans;


void init()
{
    memset(vis, false, sizeof vis);
    memset(num, 0, sizeof num);
    memset(stu, 0, sizeof stu);
    ans = maxn;
    return;
}
void dfs(int id, int room)
{
    if(room >= ans)
    {
        return;
    }
    if(id > n)
    {
        ans = min(ans, room);
        return;
    }
    for(int i = 1;i <= room;i++)
    {
        int cnt = 0;
        for(int j = 1;j <= num[i];j++)
        {
            if(!vis[id][stu[i][j]]) cnt++;
        }
        if(cnt == num[i])
        {
            stu[i][++num[i]]=id;
            dfs(id + 1, room);
            num[i]--;
        }
    }
    stu[room + 1][++num[room + 1]] = id;
    dfs(id + 1,room + 1);
    --num[room + 1];
}
int main()
{
    while(cin >> n >> m)
    {
        init();
        int u, v;
        for(int i = 1;i <= m;i++)
        {
            cin >> u >> v;
            vis[u][v] = vis[v][u] = true;
        }
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
