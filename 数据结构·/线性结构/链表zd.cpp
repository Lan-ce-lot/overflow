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



typedef int ElementType;
typedef struct LNode *List;
List Insert(ElementType X, int i, List PtrL);
struct LNode {
    ElementType Data;
    List Next;
};
struct LNode L;
List PtrL;

/* 查找 */
#define ERROR NULL

//List MakeEmpty()
//{
//    List PtrL;
//    PtrL = (List)malloc(sizeof(struct LNode));
//    if (NULL == PtrL)
//    {
//        return NULL;
//    }
//    PtrL->Next = NULL;
//    return PtrL;
//}

int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }
    return j;
}

List FindKth(int K, List PtrL)
{
    List p = PtrL;
    int i = 1;
    while (p != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K)return p;
    else return NULL;
}

List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while (p != NULL && p->Data != X)
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i, List PtrL)
{
    List p, s;
    if (i == 1)//插在表头
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i - 1, PtrL);
    if (p == NULL)
    {
        puts("参数i错误");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1)
    {
        s = PtrL;
        if (PtrL != NULL)
            PtrL = PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i - 1, PtrL);
    if (p == NULL)
    {
        printf("第%d个结点不存在", i - 1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("第%d个结点不存在", i- 1);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }

}

void ListPrint(List PtrL)
{
    while(PtrL != NULL)
    {
        PtrL->Next != NULL?printf("%d ->", PtrL->Data):printf("%d\n", PtrL->Data);
        PtrL = PtrL->Next;
    }
}

int main()
{
	
    PtrL = Insert(2, 1, PtrL);
    ListPrint(PtrL);
    PtrL = Insert(1, 2, PtrL);
    ListPrint(PtrL);
    PtrL = Insert(3, 3, PtrL);
    PtrL = Insert(3, 4, PtrL);
    cout << Length(PtrL)<< "len" << endl;
//    cout << Find(3, PtrL) << endl;
//    cout << FindKth(2, PtrL) << endl;
    ListPrint(PtrL);
    Delete(2, PtrL);
    PtrL = Insert(5, 1, PtrL);
    cout << Length(PtrL) << endl;
    ListPrint(PtrL);
//    cout << FindKth(2, PtrL) << endl;
    return 0;
}
