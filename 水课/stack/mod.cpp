#include <iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>  a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    stack<int> s;
    int cur =1;
    bool f=1;
    for(int i=0;i<n;i++)
    {
        while((s.empty()||s.top()!=a[i])&&cur<=n){
            s.push(cur);
            cur++;puts("a");
        }
        puts(" ");
        if(s.empty()||s.top()!=a[i])
        {
            f=0;
            break;
        }else
        {
            s.pop();
        }
    }    
    if(f){
        cout<<"legal"<<endl;
        
    }else
    {
        cout<<"illegal"<<endl;
    }
    return 0;
}
