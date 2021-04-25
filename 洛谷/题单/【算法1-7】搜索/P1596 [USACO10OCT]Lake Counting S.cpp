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
#include <bits/stdc++.h>
using namespace std;
int a[32][32],b[32][32];
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};
int n,i,j;
void dfs(int p,int q){
    int i;
    if (p<0||p>n+1||q<0||q>n+1||a[p][q]!=0) return;
    a[p][q]=1;//染色
    for (i=1;i<=4;i++) dfs(p+dx[i],q+dy[i]);
}
int main(){
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            cin>>b[i][j];
            if (b[i][j]==0) a[i][j]=0;
            else a[i][j]=2;
        }
    dfs(0,0);//搜索 从0，0开始搜
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++)
        if (a[i][j]==0) cout<<2<<' ';
        else cout<<b[i][j]<<' ';
        cout<<'\n';
    }
}
