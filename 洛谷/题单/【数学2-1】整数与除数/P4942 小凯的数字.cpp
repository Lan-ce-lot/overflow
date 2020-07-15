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
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n;
vector<int> div(vector<int> &A, int b, int &r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C; 
}
//#include<iostream>
//#include<cstdio>
//using namespace std;
long long k;
int main()
{
	cin>>k;
	while(k--)
	{
		long long n;
		cin>>n;
		if(n==4)
		cout<<"5"<<endl;
		else
		if(n==10)
		cout<<"11"<<endl;
		else
		cout<<(n-1)<<endl;
	}
}
////
////int main(){
////	scanf("%lld",&t);
////	while(t--){
////		scanf("%lld",&n);
////		if(n == 4) printf("5\n");
////		else if(n == 10) printf("11\n");
////		else printf("%lld\n",n - 1);
////	}
////	return 0;
////} 
//void solve()
//{
//	string str;
//	cin >> t;
//	ll a, b;
//	while (t--) {
//		scanf("%lld%lld",  &a, &b);
//		ll tem  = a + b;
//		ll tem1 = b - a + 1;
//		if (tem & 1) {
//			tem1 /= 2;
//		} else {
//			tem /= 2;
//		}		
//		
//		printf("%lld\n", (tem % 9 * tem1 % 9) % 9);
////		cin >> a >> b;
////		char ss[90];
////		str = "";
////		for (int i = a; i <= b; i++) {
////			sprintf(ss, "%d", i);
////			string tem = ss;
////			
////			str += tem;
////			
////		}
////		vector<int> A;
////		for (int i = str.size() - 1; i >= 0; i--) {
////			A.push_back(int(str[i] - '0'));
////		}
//////		cout << str << endl;
////		int r;
////		vector<int> ANS = div(A, 9, r);
////		cout << r << endl;
//////		for (int i = 0; i < ANS.size(); i++) {
//////			cout << ANS[i];
//////		}
//////		puts("");
//		
//	}
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

