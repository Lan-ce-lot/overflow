
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int mod = 666666;
typedef long long ll;
struct matrix  		//矩阵
{
    ll m[2][2];
} ans;

matrix base = {4, 3, 1, 0};

matrix multi(matrix a, matrix b)  	//矩阵相乘，返回一个矩阵
{
    matrix tmp;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            tmp.m[i][j] = 0;
            for(int k = 0;  k < 2; k++)
                tmp.m[i][j] = (tmp.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
        }
    }
    return tmp;
}

int matrix_pow(matrix a, int n)  	//矩阵快速幂，矩阵a的n次幂
{
    ans.m[0][0] = 1;
    ans.m[1][1] = 1;	//初始化为单位矩阵
    ans.m[0][1] = 0;
    ans.m[1][0] = 0;
    while(n)
    {
        if(n & 1)
            ans = multi(ans, a);
        a = multi(a, a);
        n >>= 1;
    }
    return (ans.m[0][1]*4% mod + ans.m[0][0]*233% mod) % mod;

}

int main()
{
    ll n, m;
    while (~scanf("%lld%lld", &n, &m))
    {
        printf("%lld\n",m - matrix_pow(base, n - 2));
    }
    return 0;
}
////#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
//const double pi = acos(-1.0);
//const int eps = 1e-10;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1e5;
//long long num[2][2];
//const int mod=666666;
//const int N=2;
//
//long long tmp[N][N];
//long long res[N][N];
//void mul(long long a[][2],long long b[][2],int n=2)
//
//{
//
//    memset(tmp,0,sizeof(tmp));
//
//    for(int i=0; i<n; i++)
//
//        for(int j=0; j<n; j++)
//
//            for(int k=0; k<n; k++)
//            {
//                tmp[i][j]=((a[i][k]*b[k][j])%mod+tmp[i][j])%mod;
//            }
//
//    for(int i=0; i<n; i++)
//
//        for(int j=0; j<n; j++)
//
//            a[i][j]=tmp[i][j];
//}
//
//
//
//ll Pow(long long a[][2],int n)
//
//{
//
//    memset(res,0,sizeof res);//n是幂，N是矩阵大小
//
//    for(int i=0; i<2; i++)
//        res[i][i]=1;
//
//    while(n)
//    {
//
//        if(n&1)
//            mul(res,a,2);//res=res*a;复制直接在multi里面实现了；
//        mul(a,a,2);//a=a*a
//        n>>=1;
//    }
//    return
//}
//int main()
//{
//    int n;
//
//    long long ans=0,m;
//    while(~scanf("%d%lld",&n,&m))
//    {
//        ans=0;
//        num[0][0]=4;
//        num[0][1]=3;
//        num[1][0]=1;
//        num[1][1]=0;
//        Pow(num,n-2);
//        ans=(res[0][0]*233+res[0][1]*4)%mod;
//        ans = m- ans;
//        printf("%lld\n",ans);
//
//
//    }
//}
