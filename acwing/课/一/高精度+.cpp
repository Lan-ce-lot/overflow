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
int t, n;
//==============================================================

bool cmp(vector<int> &A, vector<int> &B)//A > B 返回1
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return 1;
}



vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
//    reverse(C.begin(), C.end());
    return C;
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
    reverse(C.begin(), C.end());
    return C;
}

vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    reverse(C.begin(), C.end());
    return C;
}
vector<int> mul(vector<int> &A, vector<int> &B)
{
    vector <int> C(4005, 0);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[i + j] += A[i] * B[j];
        }
    }
    for (int i = 0; i < A.size() + B.size() - 1; i++)
    {
        if (C[i] > 9)
        {
            C[i + 1] += C[i] / 10;
            C[i] %= 10;
        }
    }
    while (C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    reverse(C.begin(), C.end());
    return C;
}

//A / B ,余数r
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
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

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);

    string a, b;
    vector<int> A, B;

    cin >> n;
    if (n == 0)
    {
        cout << 0 <<endl;
        return 0;
    }
    if (n <= 1)
    {
        cout << 1 << endl;
        return 0;
    }    vector <int> C;
    A.push_back(1);
    B.push_back(1);
    for (int i = 0; i < n - 1; i++)
    {
        C = A;
        A = B;
        B = add(C, B);
    }
    reverse(B.begin(), B.end());
    for (auto i: B)
        cout << i;
//    for (int i = a.size() - 1; i >= 0; i--)
//        A.push_back(a[i] - '0');
//    for (int i = b.size() - 1; i >= 0; i--)
//        B.push_back(b[i] - '0');


//    if (cmp(A, B))
//    {
//        C = sub(A, B);
//    }
//    else
//    {
//        cout <<'-';
//        C = sub(B, A);
//    }
//    auto C = add(A, B);
//    for (auto i : C)
//        cout << i;
    puts("");
    return 0;
}

