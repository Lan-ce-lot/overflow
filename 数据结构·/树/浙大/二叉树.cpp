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
中序遍历(Inorder Traversal (LDR))
非递归实现：
在二叉树中，中序遍历首先遍历左子树，
然后访问根结点，最后遍历右子树。
        A
      /   \
      B    C
     / \  /
    D   E F
结果：DBEAFC
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
先序遍历的非递归算法
按照根左右的顺序沿一定路径经过路径上所有的结点。
在二叉树中，先根后左再右。巧记：根左右。
        A
      /   \
      B    C
     / \  /
    D   E F
结果：ABDECF
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
            //区别在这里
            T = T->Right;
        }
    }
}

/*************************************************************************
后序遍历的非递归算法
后序遍历（LRD）是二叉树遍历的一种，
也叫做后根遍历、后序周游，可记做左右根。
后序遍历有递归算法和非递归算法两种。
在二叉树中，先左后右再根，即首先遍历左子树，
然后遍历右子树，最后访问根结点。
        A
      /   \
      B    C
     / \  /
    D   E F
结果：DEBFCA
已知前序遍历和中序遍历，就能确定后序遍历。
 ************************************************************************/

/*************************************************************************
层序遍历(bfs?)的非递归算法
队列实现
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

