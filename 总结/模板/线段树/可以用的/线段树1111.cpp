//1. 区间和模板（线段树单点更新）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50005
using namespace std;

//线段树模板

struct node{
    int l, r;
    int sum; //根据情况sum的类型改为ll 或者 ull
    int mid(){
        return (l + r)>>1;
    }
};

node tree[maxn*4];
int value[maxn];
char key[10];
int idx, v;
int cnt;

void init_tree(int root, int l, int r){
    tree[root].l = l;
    tree[root].r = r;

    if(l == r){
         tree[root].sum = value[l];
         return ;
    }
    init_tree(root<<1, l, (l + r)/2);
    init_tree(root<<1|1, (l + r)/2 + 1, r);

    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

int query_tree(int root, int l, int r){
    if(l<=tree[root].l&&r>=tree[root].r) 
        return tree[root].sum;
    int mid=tree[root].mid(),ret=0;

    if(l<=mid) ret+=query_tree(root<<1,l,r);       
    if(r>mid)  ret+=query_tree(root<<1|1,l,r);
    return ret;
}

void update_tree(int root, int idx, int v){
    if(tree[root].l == tree[root].r){
        tree[root].sum = v;
        return;
    }

    if(idx <= tree[root].mid()) update_tree(root<<1, idx, v);
    else update_tree(root<<1|1, idx, v);

    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

//------------------------------------------------------------------------------
//2.最大值模板

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 200005;
int n, m;

struct node{
    int l, r;
    int MAX_VALUE; //表示区间最大值
    int mid(){
        return (l + r) >> 1;
    }
};
node tree[maxn * 4];
int value[maxn];

void init(int root, int l, int r){
    tree[root].l = l;
    tree[root].r = r;

    if(l == r){
         tree[root].MAX_VALUE = value[l];
         return;
    }

    int m = (l + r) >> 1;

    init(root<<1, l, m);
    init(root<<1|1, m+1, r);

    tree[root].MAX_VALUE = max(tree[root<<1].MAX_VALUE, tree[root<<1|1].MAX_VALUE);
}

void update(int root, int idx, int v){
    if(tree[root].l == tree[root].r){
        tree[root].MAX_VALUE = v;
        return;
    }

    if(idx <= tree[root].mid()) update(root<<1, idx, v);
    else update(root<<1|1, idx, v);

    tree[root].MAX_VALUE = max(tree[root<<1].MAX_VALUE, tree[root<<1|1].MAX_VALUE);
}

int query(int root, int l, int r){

    if(l == tree[root].l && r == tree[root].r) return tree[root].MAX_VALUE;

    int m = tree[root].mid();

    if(l > m) return query(root<<1|1, l, r);
    else if(r <= m) return query(root<<1, l, r);
    else return max(query(root<<1, l, m), query(root<<1|1, m+1, r));
}

//------------------------------------------------------------------------------
//3.LAZY标记模板(线段树区间更新)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 100010;

struct node{
    int l, r;
    ll sum;
    int mid(){
        return (l + r)>>1;
    }
};
node tree[maxn*4];
ll value[maxn];
ll visit[maxn*4]; //懒惰标记

void pushDown(int root, int len){ //向下计算并更新线段树节点的之和

    if(visit[root]){
        visit[root<<1] += visit[root];
        visit[root<<1|1] += visit[root];
        tree[root<<1].sum += visit[root]*(len - (len>>1));
        tree[root<<1|1].sum += visit[root]*(len>>1);
        visit[root] = 0;    //每次更新完根节点需要还原
    }
}

void pushUp(int root){  //向上计算节点之和(根节点 = 左子树值 + 右子树值)
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

void init(int root, int l, int r){
    tree[root].l = l;
    tree[root].r = r;

    if(l == r){
        tree[root].sum = value[l];
        return;
    }

    int m = (l + r) >> 1;

    init(root<<1, l, m);
    init(root<<1|1, m + 1, r);

    // 等价于pushUp(root);
    //tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;

    pushUp(root);
}

void update(int root, int op, int ed, int val){ //从[op, ed]区间
    if(op == tree[root].l && ed == tree[root].r){
        visit[root] += val;
        tree[root].sum += (ll)((ed - op + 1) * val);
        return;
    }
    if(tree[root].l == tree[root].r){
        return;
    }

    int m = tree[root].mid();

    pushDown(root, tree[root].r - tree[root].l + 1);

    if(op > m) update(root<<1|1, op, ed, val);
    else if(ed <= m)update(root<<1, op, ed, val);
    else{
        update(root<<1, op, m, val);
        update(root<<1|1, m+1, ed, val);
    }
    //tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;

    pushUp(root);
}

ll query(int root, int l, int r){
    if(tree[root].l == l && tree[root].r == r){
        return tree[root].sum;
    }

    pushDown(root, tree[root].r - tree[root].l + 1); //向下更新节点值

    int m = tree[root].mid();

    if(l > m) return query(root<<1|1, l, r);
    else if(r <= m) return query(root<<1, l, r);
    else return query(root<<1, l, m) + query(root<<1|1, m + 1, r);

}
 
