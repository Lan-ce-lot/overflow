#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int mod = 666666;
typedef long long ll;
struct matrix       //矩阵
{
    ll m[2][2];
} ans;

matrix base = {4, 3, 1, 0};

matrix multi(matrix a, matrix b)    //矩阵相乘，返回一个矩阵
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

int matrix_pow(matrix a, int n)     //矩阵快速幂，矩阵a的n次幂
{
    ans.m[0][0] = 1;
    ans.m[1][1] = 1;    //初始化为单位矩阵
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
