/*************************************************************************
 > FileName:
 > Author:
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
#define debug(a) cout << "*" << a << "*" << endl
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int f[9];
ll n, k;
int main()
{

    int v=0;//判断标志
    double A,B,C;
    int  a,b,c;
    int m,t,flag;
    cin>>A>>B>>C;
    int n[9];

    if(A<B&&B<C)
    {
        flag = 0;
        for(int i=123; i<1000*A/C; i++)
        {
            int n[9]= {0};
            t=0;
            a=i;
            b=B/A*i;
            c=C/A*i;
            n[2]=a%10;//个位
            n[0]=a/100;//百位
            n[1]=(a/10)%10;//十位
            n[5]=b%10;
            n[3]=b/100;
            n[4]=(b/10)%10;
            n[8]=c%10;
            n[6]=c/100;
            n[7]=(c/10)%10;

//********************************************************************************
            if (!(n[0] * n[1] * n[2] * n[3] * n[4] * n[5] * n[6] * n[7] * n[8]))
                continue;
            for (int i = 0; i < 9; i++)
                f[i] = n[i];
            sort(f, f + 9);
            int count1 = unique(f, f + 9) - f;
            if (count1 != 9)
                continue;
//********************************************************************************

            for(m=0; m<9; m++)
            {
                for(int k=m+1; k<8; k++)
                {
                    if(n[m]==n[k])
                    {
                        t=1;
                        break;
                    }
                }
            }


            if(t==0)
            {
                printf("%d %d %d\n",a,b,c);
                flag++;
            }
        }
        if(flag==0)
            cout<<"No!!!"<<endl;
        return 0;
    }
}
