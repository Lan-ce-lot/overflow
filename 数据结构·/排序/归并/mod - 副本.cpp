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

int count1 = 0;//归并排序求逆序数的

void My_merge(int arr[], int l, int mid, int r)
{
    int aux[r - l + 1];
    for (int m = l; m <= r; m++)
    {
        aux[m - l] = arr[m];
    }

    int i = l, j = mid + 1;

    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] < aux[j - l])
        {
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
            count1 += (mid - i + 1);//emm
        }
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return ;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    My_merge(arr, l, mid, r);
}

//void mergesort(int arr[],int n)//迭代
//{
//    for(int sz=1;sz<=n;sz+=sz)
//    {
//        for(int i=0;i+sz<n;i+=sz+sz)//i+sz防止越界
//        {//对arr[i...sz-1]和arr[i+sz.....i+2*sz-1]进行排序
//            My_merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));    //min函数防止越界
//        }
//    }
//}

void My_merge_sort(int arr[], int n)//duoyu
{
    merge_sort(arr, 0, n - 1);
}

int t, n, a[maxn], x[maxn];
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            x[i] = a[i];
        }

        count1 = 0;
        My_merge_sort(x, n);
        int ans = count1, sum = count1;
        for (int i = 0; i < n - 1; i++)
        {
            sum = sum - 2 * a[i] + n - 1;
            ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
//46MS	1388K
