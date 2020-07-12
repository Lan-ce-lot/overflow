/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }

    //删除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size()) t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}


int t, n;
string str;
int a[maxn];
int addc = 1;
vector<int> A, ans;
void solve()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+')
        {
            addc++;
        }
        else
        {
            A.push_back(str[i] - '0');
        }
    }
    sort(A.begin(), A.end(), greater<int>());
//    for (auto i: A)
//        cout << i ;
//    puts("");
    int temp = 0;
    if (addc == 1)
    {
        reverse(A.begin(), A.end());
        for (auto i: A)
            cout << i;
        puts("");
        return;
    }
    for (int i = 0; i < A.size(); )
    {
        for (int j = 1; j <= addc && i < A.size(); j++, i++)
        {
            temp += A[i];
        }
        ans.push_back(temp % 10);
        temp /= 10;
    }
    while (temp)
    {
        ans.push_back(temp % 10);
        temp /= 10;
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i;
    puts("");


}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

