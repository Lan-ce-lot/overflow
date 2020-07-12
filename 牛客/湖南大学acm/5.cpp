#include<iostream>
using namespace std;
 
int main(){
    long long mod = 1e9+7;
    int n;
    cin>>n;
    long long a[n+1];a[0]=a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=(i*a[i-1]+(i-1)*a[i-2])%mod;
    }
    cout<<a[n];
    return 0;
}
