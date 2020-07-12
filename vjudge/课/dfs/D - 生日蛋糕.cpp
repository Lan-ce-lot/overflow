///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
////#include <bits/stdc++.h>
////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <sstream>
//#include <vector>
//#include <cstdio>
//#include <bitset>
//#include <string>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
//const int mod = 1e9 + 7;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1000005;
////sacnf("%lf") printf("%f")
//ll read()
//{
//    ll x = 0,f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		f = -1;
//		ch = getchar();
//	}
//    while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//    return x * f;
//}
//int t, n, m;
//
//
//int min_s = INF;
//
//void dfs(int n_, int m_, int s, int n__, int h__) {
//
//    if (m_ == 0) {
//        if (n_ == n)
//            min_s = min(min_s, s);
//        return ;
//    }
//    for (int i = n__ - 1; i >= m_; i--) {
//        if (m_ == m) s = i * i;
//        for (int j = h__ - 1; j >= m_; j--) {
//            dfs(n_ + i * i * j, m_ - 1, s + j * i * 2, i, j);
//        }
//    }
//}
//// 体积V = π * R^2 * H
//// 侧面积A' = 2 * π * R * H
//// 底面积A = π * R * 2
//// n m
//void solve()
//{
//    scanf("%d%d", &n, &m);
//    dfs(0, m, 0, 100, 10000);
//    cout << min_s << endl;
//}
//
//int main()
//{
//
////    freopen("F:/Overflow/in.txt","r",stdin);
////    ios::sync_with_stdio(false);
//    solve();
//    return 0;
//}
//

#include<stdio.h>
#define in(a,b) (a<b?a:b)
int n,m;
int minv[21],mins[21];
int bests;

void dfs(int v,int s,int level,int r,int h)//level为搜索深度,从底层m层向上搜,r,h分别为该层的半径和高度
{
    if(level==0)//搜索完成,则更新最小面积值
    {
        if(v==n&&s<bests)
            bests=s;
        return ;
    }
    if(v+minv[level-1]>n||s+mins[level-1]>bests||2*(n-v)/r+s>=bests)//剪枝
        return ;
    int i,j,hh;
    for(i=r-1;i>=level;i--)//按递减顺序枚举level层蛋糕半径的每一个可能值,这里第level层的半径最小值为level
    {
        if(level==m)//底面积作为外表面积的初始值(总的上表面积,以后只需计算侧面积)
            s=i*i;
        hh=in((n-v-minv[level-1])/(i*i),h-1); //最大高度,即level层蛋糕高度的上限,(n-v-minv[level-1])表示第level层最大的体积
        for(j=hh;j>=level;j--)//同理,第level层的最小高度值为level
            dfs(v+i*i*j,s+2*i*j,level-1,i,j);//递归搜索子状态
    }
}
int main()
{
    int i;
    minv[0]=0;
    mins[0]=0;
    for(i=1;i<=20;i++)//从顶层向下计算出最小体积和表面积的可能值
    {
        //从顶层（即第一层）到第i层的最小体积minv[i]成立时第j层的半径和高度都是j
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
    while(scanf("%d%d",&n,&m)==2)
    {
        bests=0x7fffffff;
        dfs(0,0,m,n+1,n+1);
        if(bests==0x7fffffff)
            printf("0\n");
        else
            printf("%d\n",bests);
    }
    return 0;
}
