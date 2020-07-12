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
const int maxn = 1e5 + 5;
char str0[6] = "wrong";
bool flag[5];
struct node
{
    char ch;
    int v, po;
}a[maxn];

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

ll num[maxn];
char  c,str1[maxn];
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0,j = 0; i < n; i++)
    {
        scanf(" %c", &c);
        if (c == 'w' || c == 'r' || c == 'o' || c == 'n' || c == 'g')
        {
            a[j].po = i;
            a[j++].ch = c;

        }
    }
    for (int i = 0, j = 0,k = 0; i < n; i++)
    {
        int b;
        scanf("%d", &b);
        if (a[j].po == i)
        {
            if (a[j].ch == 'w')
            {

                str1[k] = a[j].ch;
                flag[0] = 1;
                a[k++].v = b;
            }

            else if (a[j].ch == 'r' && flag[0])
            {
                str1[k] = a[j].ch;
                flag[1] = 1;
                a[k++].v = b;
            }
            else if (a[j].ch == 'o' && flag[1])
            {
                str1[k] = a[j].ch;
                flag[2] = 1;
                a[k++].v = b;
            }
            else if (a[j].ch == 'n' && flag[2])
            {
                str1[k] = a[j].ch;
                flag[3] = 1;
                a[k++].v = b;
            }
            else if (a[j].ch == 'g' && flag[3])
            {
                str1[k] = a[j].ch;
                flag[4] = 1;
                a[k++].v = b;
            }
            j++;
        }
    }


//    puts(str1);
    int l = strlen(str1);

    char strF[maxn];
    int s_v[maxn];
    memset(flag, 0, sizeof(flag));
    for (int i = l, j = 0; i >= 0; i--)
    {
        if (str1[i] == 'g')
        {
            num[(int)str1[i]] += a[i].v;
            strF[j++] = 'g';
            flag[4] = 1;
        }
        else if (str1[i] == 'n'&& flag[4])
        {
            num[(int)str1[i]] += a[i].v;
            strF[j++] = 'n';
            flag[3] = 1;
        }
        else if (str1[i] == 'o'&& flag[3])
        {
            num[(int)str1[i]] += a[i].v;
            strF[j++] = 'o';
            flag[2] = 1;
        }
        else if (str1[i] == 'r'&& flag[2])
        {
            num[(int)str1[i]] += a[i].v;
            strF[j++] = 'r';
            flag[1] = 1;
        }
        else if (str1[i] == 'w'&& flag[1])
        {
            num[(int)str1[i]] += a[i].v;
            strF[j++] = 'w';
            flag[0] = 1;
        }
    }
//    cout << strF <<endl;




    ll max1 = INF;
    for (int i = 0; i < 5; i++)
    {
        max1 = min(max1, num[(int)str0[i]]);
    }
    printf("%lld\n", max1);
    return 0;
}

