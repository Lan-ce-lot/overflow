#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back
#define abs(a) (a)>0?(a):-(a)
#define lalal puts("*******");
typedef long long int LL ;
/*******************************/
const int maxn = 1e4 + 5;
int ma[maxn][maxn];
int vis[maxn][maxn];
int xx[maxn], yy[maxn]; //横纵坐标
struct node   //点
{
    int x, y, col;
} bad[maxn];

map<int, int >mx, my; //离散化的映射
LL vx[maxn], vy[maxn]; //离散化后横纵坐标的价值

LL val[maxn];

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int main()
{
    int _, p;
    scanf("%d", &_);
    p = 0;
    while(_--)
    {
        /******这是一堆预处理******/
        mx.clear(), my.clear();
        memset(val, 0, sizeof(val));

        int n, m, num, num1, num2;
        scanf("%d%d", &n, &m);
        scanf("%d", &num), num1 = num2 = num;
        for(int i = 1; i <= num; i++)
        {
            scanf("%d%d", &bad[i].x, &bad[i].y);
            xx[i] += bad[i].x, yy[i] = bad[i].y;
        }
        xx[0] = 1, yy[0] = 1, xx[num + 1] = n, yy[num + 1] = m ; //离散化图的边界

        int hang = 1, lie = 1, pre = 1;
        /**************离散化行**************/

        sort(xx, xx + num1 + 2);
        num1 = unique(xx, xx + num1 + 2) - xx;
        for(int i=0;i<num1;i++)  printf("%d ",xx[i]);  puts("");
        for(int i = 0; i < num1; i++)
        {
            if(i && xx[i] != xx[i - 1] + 1)
                vx[hang] = xx[i] - pre - 1, hang++;
            vx[hang] = 1, mx[xx[i]] = hang++;
            pre = xx[i];

        }

        /**************离散化列**************/
        pre = 1;
        sort(yy, yy + num2 + 2);
        num2 = unique(yy, yy + num2 + 2) - yy;
        for(int i = 0; i < num2; i++)
        {
            if(i && yy[i] != yy[i - 1] + 1)
                vy[lie] = yy[i] - pre - 1, lie++;
            vy[lie] = 1, my[yy[i]] = lie++;
            pre = yy[i];
        }
        //------------------------------------
//        for (int )
//        {
//            cout <<
//
//        }

    }

}
