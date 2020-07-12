#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
int a[1005],b[1005],vis[1000005];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {

        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i]>=b[j])
                {

                    vis[a[i]-b[j]]=1;

                }

        for(int i=0;; i++)
        {
            if(!vis[i])
            {
                printf("%d\n",i);
                break;
            }
        }

    }
    return 0;
}
