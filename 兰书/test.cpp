//
// Created by Woft6c on 2021/3/14.
//


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    ll ans=495L;
    while (cin>>n) {
    	if(n==1)cout<<"0"<<endl;
    else if(n==2)cout<<"11"<<endl;
    else if(n==3)cout<<"33"<<endl;
    else if(n==4)cout<<"66"<<endl;
    else if(n==5)cout<<"110"<<endl;
    else if(n==6)cout<<"165"<<endl;
    else if(n==7)cout<<"231"<<endl;
    else if(n==8)cout<<"308"<<endl;
    else if(n==9)cout<<"396"<<endl;
    else if(n==10)cout<<"495"<<endl;
    else {
        for(ll i=12;i<=n+1;i++){
            ll num=i*9;
            ll sum=0;
            while(num){
                sum=sum+num%10;
                num/=10;
            }
            if(sum>9){
                n++;
                continue;
            }
            else ans=ans+i*9;
            //cout<<ans<<" "<<i*9<<endl;
        }
        cout<<ans<<endl;
    }
	}
    
    return 0;
}
