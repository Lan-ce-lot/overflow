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
string str;
vector<char> S;
vector<char> S_;
vector<int> ind;
bool vis[maxn];
//void turn(char a) {
//	if (a == '(') {
//		printf(')');
//	} else if (a == ')') {
//		printf('(');
//	} else if (a == '[') {
//		printf(']');
//	} else {
//		printf('[');
//	}
//}
int  q[101],top;
char c[101],b[101];
int main1()
{
    int i,l;
    scanf("%s",c);
    l=strlen(c);
    for (i=0;i<l;i++)
    {
        if (c[i]=='(') {q[++top]=i; b[i]=')';}
        if (c[i]=='[') {q[++top]=i; b[i]=']';}
        if (c[i]==')'||c[i]==']')
            if (!top||b[q[top]]!=c[i])
                if (c[i]==')') b[i]='('; else b[i]='[';
            else b[q[top--]]=' ';
    }
    for (i=0;i<l;i++)
    {
        if (b[i]=='('||b[i]=='[') printf("%c",b[i]);
        printf("%c",c[i]);
        if (b[i]==')'||b[i]==']') printf("%c",b[i]);
    }}
void solve()
{
	main1();
//	while (cin >> str) {
//		S.clear();
//		ind.clear();
//		memset(vis, 0, sizeof vis);
//			for (int i = 0; i < str.size(); i++) {
////		vector<int>::iterator it=find(temp.begin(),temp.end(),3);
//		if (str[i] == '(') {
//			
//			S.push_back('(');
//			ind.push_back(i);
//			
//		} else if (str[i] == '[') {
//			S.push_back('[');
//			ind.push_back(i);
//		} else if (str[i] == ')' && S.size() && S.back() == '(') {
//			S.pop_back();
//			ind.pop_back();
//		} else if (str[i] == ']' && S.size() && S.back() == '[') {
//			S.pop_back();
//			ind.pop_back();
//		} else {
//			S.push_back(str[i]);
//			ind.push_back(i);
//		}
//	}
//	
////	for (auto i : S) {
////		cout << i << endl;
////	}
//	for (int i = 0; i < ind.size(); i++) {
//		vis[ind[i]] = 1;
//	}
//	for (int i = 0; i < str.size(); i++) {
//		if (vis[i] == 1) {
//			if (str[i] == '[') {
//				printf("[]");
//			} else if (str[i] == '(') {
//				printf("()");
//			} else if (str[i] == ']') {
//				printf("[]");
//			} else if (str[i] == ')') {
//				printf("()");
//			}
//		} else {
//			printf("%c", str[i]);
//		} 
//	}
//	puts("");
//	}

}
// ()(])()()
// ((([)]
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

