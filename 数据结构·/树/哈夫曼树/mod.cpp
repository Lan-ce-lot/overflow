/*************************************************************************
 > FileName:
 > Author:      Lance
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
const int MinData = -INF;
const int MaxSize = maxn;
typedef int ElementType;
typedef struct TreeNode *HuffmanTree;
typedef struct HeapStruct *MinHeap;

MinHeap Create(int MaxSize);
ElementType DeleteMin(MinHeap H);
void Insert(MinHeap H, ElementType item);
bool IsFull(MinHeap H);
bool IsEmpty(MinHeap H);

struct TreeNode
{
    int Weight;
    HuffmanTree Left, Right;
};

struct HeapStruct
{
    ElementType *Elements;//heap array
    int Size;
    int Capacity;//最大容量
};

HuffmanTree Huffman(MinHeap H)
{
    int i;
    HuffmanTree T;
    H = Create(MaxSize);
    for (i = 1; i < 1000; i++)
    {
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    T = DeleteMin(H);
    return T;
}

MinHeap Create(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MinData;//哨兵，小于堆中所有可能元素
    return H;
}
/*************************************************************************

 ************************************************************************/
void Insert(MinHeap H, ElementType item)
{
    int i;
    if (IsFull(H))
    {
        printf("最大堆已满\n");
        return;
    }
    i = ++H->Size;
    for (; H->Elements[i / 2] > item; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = item;
}
/*************************************************************************

 ************************************************************************/
ElementType DeleteMin(MinHeap H)
{
    int Parent, Child;
    ElementType MinItem, temp;
    if (IsEmpty(H))
    {
        printf("最大堆空\n");
        return -1;
    }
    MinItem = H->Elements[1];
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;
        if (temp >= H->Elements[Child])
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}
/*************************************************************************

 ************************************************************************/
bool IsFull(MinHeap H)
{
    return (H->Size == H->Capacity);
}
/*************************************************************************

 ************************************************************************/
bool IsEmpty(MinHeap H)
{
    return (H->Size == 0);
}

/*************************************************************************

 ************************************************************************/
void Print(MinHeap H)
{
    int co = 2;
    for (int i = 1; i <= H->Size; i++)
    {
        i > co - 1 ? puts(""), co <<= 1 : i;
        printf("%d ", H->Elements[i]);
    }
    puts("\n");
    return;
}

int main()
{

    return 0;
}

