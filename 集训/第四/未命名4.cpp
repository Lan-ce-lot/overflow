#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
    {
        return true;
    }
    return false;
}

bool judge[110];

int main()
{
    int n;//cin>>n;

    string str,tmp;
    cin>>str;
    memset(judge,false,sizeof(judge));
    int siz = str.size();
    for(int i=0;i<n;i++)
    {
        if(isvowel(str[i]))
        {
           if(isvowel(str[i+1]))
           {
               judge[i+1] = true;
           }

        }

    }
    for(int i=0;i<n;i++)
        if(!judge[i])
    {
        cout<<str[i];
    }
    return 0;
}
