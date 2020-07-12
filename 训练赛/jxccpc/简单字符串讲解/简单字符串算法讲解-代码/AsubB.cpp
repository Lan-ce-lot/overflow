#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
string s1, s2;
bool vis[maxn]={false};
int main()
{
    cin.tie(nullptr);
    getline(cin, s1);
    getline(cin, s2);
    //方法1：
    /*for(int i = 0; i < s1.length(); i++)
    {
        if(s2.find(s1[i]) == string::npos)
            printf("%c", s1[i]);
    }*/

    //方法2：
    /*for(int i = 0; i < s2.length(); i++)
        vis[s2[i]]=true;
    for(int i = 0; i < s1.length(); i++)
        if(!vis[s1[i]])
            printf("%c", s1[i]);*/
    return 0;
}