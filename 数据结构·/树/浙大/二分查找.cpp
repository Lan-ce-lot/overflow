/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int a[maxn];

typedef int ElementType;
struct node
{
    int Element[maxn];
    int Length;
};
typedef node *List;

List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct node));
    return PtrL;
}

int BinarySearch(List Tbl, ElementType K)
{
    int l, r ,mid, NoFound = -1;

    l = 1;
    r = Tbl->Length;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (K < Tbl->Element[mid])
            r = mid - 1;
        else if (K > Tbl->Element[mid])
            l = mid + 1;
        else
            return mid;
    }
    return NoFound;
}

List case1;

bool cmp(node a, node b)
{
    return a.Element < b.Element;
}

int main()
{
    case1 = MakeEmpty();
    for (int i = 1; i <= 10; i++)
    {
        cin >> case1->Element[i];
        i == 10?cout << case1->Element[i] << endl:cout << case1->Element[i] << ' ';

    }
    case1->Length = 10;
    int n;
    cin >> n;
    cout << BinarySearch(case1, n);//1 2 3 4 5 6 7 8 9 10
    return 0;
}
