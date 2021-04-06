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
int TI(string a) {
	return a - '0';
}
string TC(int a) {
	return a + '0';
}
vector<int> add(vector<int> A,vector<int> B) {
    vector<int> C;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++){
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    reverse(C.begin(), C.end());
    return C;
}
string add(string A, string B) {
    string C;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++){
        if (i < A.size()) t += TI(A[i]);
        if (i < B.size()) t += TI(B[i]);
        C += TC(t % 10);
        t /= 10;
    }
    if (t)
        C += '1';
    reverse(C.begin(), C.end());
    return C;
}
vector<int> sub(vector<int> A, vector<int> B) {
    vector<int> C;
    reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    reverse(C.begin(), C.end());
    return C;
}
string sub(string A, string B) {
    string C;
    reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = TI(A[i]) - t;
        if (i < B.size())
            t -= TI(B[i]);
        C += TC((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == '0')
        C.pop_back();
    reverse(C.begin(), C.end());
    return C;
}
vector<int> mul(vector<int> A, ll B) {
	vector<int> C;
	int t = 0;
	for (int i = A.size() - 1; i >= 0 || t; i--) {
		if (i >= 0) t += A[i] * B;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) 
		C.pop_back();
	reverse(C.begin(), C.end());
	return C;
}
string mul(string A, ll B) {
	string C;
	int t = 0;
	for (int i = A.size() - 1; i >= 0 || t; i--) {
		if (i >= 0) t += TI(A[i]) * B;
		C += TC(t % 10);
		t /= 10;
	}
    while (C.size() > 1 && C.back() == '0')
        C.pop_back();
	reverse(C.begin(), C.end());
	return C;
}
vector<int> mul(vector<int> A, vector<int> B) {
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
    vector <int> C(9005, 0);
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    for (int i = 0; i < A.size() + B.size() - 1; i++)
        if (C[i] > 9)
            C[i + 1] += C[i] / 10, C[i] %= 10;
            
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
        
    reverse(C.begin(), C.end());
    return C;
}

vector<int> div(vector<int> A, ll b, int &r) {
	vector<int> C;
	r = 0;
	for (int i = 0; i < A.size(); i++) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) 
		C.pop_back();
		
	reverse(C.begin(), C.end());
	return C;
}

vector<int> turn(string a) {
	vector<int> res;
	for (int i = a.size() - 1; i >= 0; i--) res.push_back(a[i] - '0');
	reverse(res.begin(), res.end());
	return res;
}
vector<int> MAX(vector<int> A, vector<int> B) {
	if (A.size() > B.size()) return A;
	else if (A.size() < B.size()) return B;
	else
		for (int i = 0; i < A.size(); i--)
			if (A[i] > B[i]) return A;
			else if (A[i] < B[i]) return B;
	return A;
}

void print(vector<int> A) {
	for (auto it : A) cout << it;
	puts("");
}

void solve()
{
	string a, b;
	int c;
	cin >> a >> b;
//	cout << add(a, b) << endl;
//	cout << sub(a, b) << endl;
	cout << mul(a, b) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

