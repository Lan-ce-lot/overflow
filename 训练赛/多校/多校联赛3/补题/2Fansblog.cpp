/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
//(p-2)!=1(mod p)
//(p-3)!=1*(p-2)^(p-2)(mod p)
//(p-4)!=1*(p-2)^(p-2)*(p-3)^(p-2)(mod p)
 ************************************************************************/
#include<iostream>
#include<iomanip>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;
typedef unsigned long long ll;
ll P;
unsigned long long kuai(__int128 a, __int128 b) //¿ìËÙÃÝ
{
    __int128 sum = 1;
    a = a % P;
    while(b > 0)
    {
        if(b % 2 == 0)
        {
            a = (a * a) % P;
            b = b / 2;
        }
        else
        {
            sum = (sum * a) % P;
            a = (a * a) % P;
            b = b / 2;
        }
    }
    return sum;
}
bool prime( long long a)//
{
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int T;
    __int128 Q, ans;
    scanf("%d", &T);
    while(T--)
    {
        cin >> P;
        Q = P - 2;
        ans = 1;
        for(int i = 2; !prime(Q); Q--, i++)
        {
            ans = (ans * kuai(P - i, P - 2)) % P;
        }
        cout << (ll)ans << endl;
    }
}
