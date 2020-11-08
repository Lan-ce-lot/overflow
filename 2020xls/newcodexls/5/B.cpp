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
//int N;
//int p[maxn]; 
//void shuffle(int a[], int n) {
//    int b[n];
//    for (int i = 0; i < n; i++) {
//        b[i] = a[i];
//    }
//    for (int i = 0; i < n; i++) {
//        a[i] = b[p[i]];
//    }
//}
//
//void tonnnny_sort(int a[], int n) {
////    assert (n == N); // Tonnnny appointed!
//    while (!is_sorted(a, n)) {
//        shuffle(a, a + n);
//    }
//}
//
//void solve()
//{
//	cin >> t;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	
//	tonnnny_sort(, n);
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
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
const int maxm=1e5+5;
int mark[maxm];
int a[maxm];
int n;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>cir;
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            int cnt=0;
            int x=i;
            while(!mark[x]){
                mark[x]=1;
                cnt++;
                x=a[x];
            }
            cir.push_back(cnt);
        }
    }
    int ans=cir[0];
    cout << ans << endl;
    for(int i=1;i<(int)cir.size();i++){
        ans=lcm(ans,cir[i]);
    }
//    string str = ;
	
    cout<<ans<<endl;
    return 0;
}

