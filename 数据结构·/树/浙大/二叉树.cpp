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

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;

struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


/*************************************************************************
�������(Inorder Traversal (LDR))
�ǵݹ�ʵ�֣�
�ڶ������У�����������ȱ�����������
Ȼ����ʸ���㣬��������������
        A
      /   \
      B    C
     / \  /
    D   E F
�����DBEAFC
*************************************************************************/
void InOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    stack<BinTree> S;
    while (T || !S.empty())
    {
        while(T)
        {
            S.push(T);
            T = T->Left;
        }
        if (!S.empty())
        {
            T = S.top();
            S.pop();
            printf("%5d", T->Data);
            T = T->Right;
        }
    }
}


/*************************************************************************
��������ķǵݹ��㷨
���ո����ҵ�˳����һ��·������·�������еĽ�㡣
�ڶ������У��ȸ��������ҡ��ɼǣ������ҡ�
        A
      /   \
      B    C
     / \  /
    D   E F
�����ABDECF
 ************************************************************************/
void PreOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    stack S;
    while (T || !S.empty())
    {
        while(T)
        {
            S.push(T);
            printf("%5d", T->Data);//
            T = T->Left;
        }
        if (!S.empty(S))
        {
            T = S.pop();
            //����������
            T = T->Right;
        }
    }
}

/*************************************************************************
��������ķǵݹ��㷨
���������LRD���Ƕ�����������һ�֣�
Ҳ��������������������Σ��ɼ������Ҹ���
��������еݹ��㷨�ͷǵݹ��㷨���֡�
�ڶ������У���������ٸ��������ȱ�����������
Ȼ������������������ʸ���㡣
        A
      /   \
      B    C
     / \  /
    D   E F
�����DEBFCA
��֪ǰ��������������������ȷ�����������
 ************************************************************************/

/*************************************************************************
�������(bfs?)�ķǵݹ��㷨
����ʵ��
************************************************************************/

void LevelOrderTraversal(BinTree BT)
{
    queue Q;
    Bintree T;
    Q.push(BT);
    while (!q.empty())
    {
        T = Q.pop();
        printf("%d\n", T->Data);
        if (T->Left)
            Q.push(T->Left);
        if (T->right)
            Q.push(T->Right);
    }
}

int main()
{

    return 0;
}

