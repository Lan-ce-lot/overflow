#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int cmp(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n,b[1000]={0};
	cin>>n;
    string str;
    cin>>str;
    int l = str.size();
    for(int i=0;i<n;i++)
    {
        if(cmp(str[i]))
        {
           if(cmp(str[i+1]))
           {
               b[i+1] = 1;
           }

        }

    }
    for(int i=0;i<n;i++)
        if(!b[i])
    {
        cout<<str[i];
    }
    return 0;
}
