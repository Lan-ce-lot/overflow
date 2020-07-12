/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: lineaer list
 ************************************************************************/
#include <iostream>
#include <cstdlib>
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
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;



typedef struct LNode *List;
typedef int ElementType;
List MakeEmpty();
ElementType FindKth(int K, List L);
int Find(ElementType X, List L);
void Linsert(ElementType X, int i, List L);
void Delete(int i, List L);
int Length(List L);

struct LNode
{
    ElementType Data[maxn];
    int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

int Find(ElementType X, List Ptrl)
{
    int i = 0;
    while (i <= PtrL->Last && Ptrl->Data[i] != X)i++;
    if (i > Ptrl->Last)return -1;//未找到返回-1
    else return i;
}

void Linsert(ElementType X, int i, List Ptrl)
{
    int j;
    if (Ptrl->Last == maxn - 1)
    {
        puts("表满");
        return;
    }
    if (i < 1 || i > Ptrl->Last + 2)
    {
        puts("位置不合法");
        return;
    }
    for (j = Ptrl->Last; j >= i - 1; j--)
        Ptrl->Data[j + 1] = Ptrl->Data[j];
    Ptrl->Data[i - 1] = X;
    Ptrl->Last++;
    return;
}

void Delete(int i, List PtrL)
{
    int j;
    if (i < 1 || i >PtrL->Last + 1)
    {
        puts("不存在");
        return ;
    }
    for (j = i; j <= PtrL->Last; j++)
        PtrL->Data[j - 1] = PtrL->Data[j];
    PtrL->Last--;
    return ;
}

int main()
{
    PtrL = MakeEmpty();
    Linsert(1, 1, PtrL);
    cout << Find(10, PtrL) << endl;
    Linsert(10, 2, PtrL);
//    Delete(1, PtrL);
    cout << Find(10, PtrL) << endl;
    return 0;
}

