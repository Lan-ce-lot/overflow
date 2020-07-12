#include <bits/stdc++.h>
#define ll long long
using namespace std;
string str;
ll len;
bool flag ;
 
void mod(int d){
    ll ans = 0;
    int pos = 0;
    for(;pos < len;pos++){
        ans = (ans * 10 + (str[pos] - '0'))%d;
    }
    if(ans == 0 && flag){
        flag = 0;
        puts("Yes");
    }
    if(ans == 0)
        printf("%d ",d);
}
 
int main(){
    flag = true;
    cin>>str;
    len = str.length();
    mod(3);
    mod(5);
    mod(8);
    mod(11);
    if(flag)
      puts("No");
 
    return 0;
}
