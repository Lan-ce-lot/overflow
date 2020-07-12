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


/*
快速排序接口：
数组头， 左端点，右端点
调用(q, 0, n - 1);
*/
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        //while (q[--i] < x);
        //while (q[++j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

/*
归并排序接口:
数组头， 左端点，右端点
调用(q, 0, n - 1);
*/
int temp[maxn];
ll con = 0;//逆序对Count Inversions
void merge_sort(int q[], int l ,int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    //递归
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

//    merge(q + l, q + mid + 1, q + mid + 1, q + r + 1, temp);
    //合并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else//逆序对Count Inversions
        {
            con += mid - i + 1;
            temp[k++] = q[j++];
        }

    while (i <= mid)
    {
        temp[k++] = q[i++];
    }

    while (j <= r)
    {

        temp[k++] = q[j++];
    }


    //改变原数组
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
}


int a[1000010];
int main()
{
    //freopen("F:/Overflow/in.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    cout << con << endl;
//    sort(a, a + n);
//    quick_sort(a, 0, n - 1);
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d ", a[i]);
//    }

//    ios::sync_with_stdio(false);
    return 0;
}

