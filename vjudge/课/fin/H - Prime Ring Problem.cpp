#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
int n,prime[100]= {0},huan[10]= {0,1},see[22];

ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int t;
int a[maxn];

void DFS(int s,int k)
{
    int i;
    if(s>n)
    {
        if(prime[huan[1]+huan[s-1]])
        {
            for(i=1; i<=n; i++)
            {
                if(i>1)
                    cout<<" ";
                cout<<huan[i];
            }
            cout<<endl;
        }
        else
            return;
    }
    for(i=2; i<=n; i++)
    {
        if(k)
            for(int j=1; j<22; j++)
                see[j]=1;
        if(prime[i+huan[s-1]]&&see[i])
        {
            huan[s]=i;
            see[i]=0;
            DFS(s+1,0);
            see[i]=1;
        }
    }
}

void solve()
{
    int i,j,k,l=1;
    for(i=1; i<100; i+=2)
        prime[i]=1;
    prime[1]=0;
    prime[2]=1;
    for(i=3; i<100; i++)
        for(j=i+i; j<100; j+=i)
            prime[j]=0;
    while(cin>>n)
    {
        cout<<"Case "<<l++<<":"<<endl;
        DFS(2,1);
        cout<<endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

