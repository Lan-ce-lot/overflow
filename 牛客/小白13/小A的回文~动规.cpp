#include<bits/stdc++.h>
using namespace std;
bool palin[10001][10001];
int main()
{
    string s;
    cin>>s;
    s+=s;
    int n=s.length(),ans=0;
    for(int i=1;i<n;i++)
        for(int j=i;j>=0&&i-j+1<=n/2;j--)
            if(s[i]==s[j]&&((i-j<2)||palin[j+1][i-1]))
            {
                palin[j][i]=1;
                ans=max(ans,i-j+1);
            }
    cout<<ans<<endl;
    return 0;
}
