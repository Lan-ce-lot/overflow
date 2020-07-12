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
//int t, n;
//
//void solve()
//{
//
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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Matrix{
    int m[2][2];
};
Matrix mul(Matrix a,Matrix b){
    Matrix ans;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans.m[i][j] = 0;
            for(int k = 0; k < 2; k++){
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j] % 7) % 7;
            }

        }
    }
    return ans;
}
int main(){
    int A,B,n;
    while(scanf("%d%d%d",&A,&B,&n) != EOF){
        if(A == 0 && B == 0 && n == 0) break;
        if(n <= 2){
            printf("1\n");
            continue;
        }
        Matrix a,ans;
        a.m[0][0] = A;
        a.m[0][1] = B;
        a.m[1][0] = 1;
        a.m[1][1] = 0;
        ans.m[0][0] = ans.m[1][1] = 1;
        ans.m[0][1] = ans.m[1][0] = 0;
        n -= 2;
        while(n){
            if(n & 1)
                ans = mul(ans,a);
            n >>= 1;
            a = mul(a,a);
        }
        printf("%d\n",(ans.m[0][0] + ans.m[0][1]) % 7);
    }
    return 0;
}
