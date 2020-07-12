#include<iostream>
#include<string.h>
#define M 1000000007
using namespace std;
int main(){
    char l[100001],m[100001];
    cin>>l>>m;
    long long n=strlen(l),t=0,i,a=2,ans=1;
    for(i=0;i<n;i++)t=(t*10+l[i]-'0')%(M-1);
    while(t>0){
        if(t&1) ans=ans*a%M;
        a=a*a%M;
        t>>=1;
    }
    cout<<ans;
}
