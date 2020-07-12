#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int tot=0,len,k;
        cin>>s; 
        len=s.length();
        for(int j=len-1;j>=0;j--)
        {
            tot+=(int)pow(s[j]-'0',len);
        }
        k=atoi(s.c_str()); 
        if(k==tot)ans++;
    }
    cout<<ans;
}

