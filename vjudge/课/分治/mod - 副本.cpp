/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int k,l,i,j;
        double s[101][101],o[101][101],pa,pb;
        cin>>pa>>pb>>k>>l;
        pa/=100;
        pb/=100;
        s[1][0]=pa;
        o[1][0]=1-pb;
        s[0][1]=1;
        o[0][1]=1;
        for (i=2; i<=l; i++)
        {
            s[0][i]=1;
            o[0][i]=1;
            s[i][0]=s[i-1][0]*pa;
            o[i][0]=o[i-1][0]*pa;
        }
        for (i=1; i<=l; i++)
            for (j=1; j<l; j++)
            {
                s[i][j]=pa*s[i-1][j]+(1-pa)*o[i][j-1];
                o[i][j]=(1-pb)*s[i-1][j]+pb*o[i][j-1];
            }
        pa=s[l][l-1];
        pb=o[l][l-1];
        l=k;
        s[1][0]=pa;
        o[1][0]=pb;
        s[0][1]=1;
        o[0][1]=1;
        for (i=2; i<=l; i++)
        {
            s[0][i]=1;
            o[0][i]=1;
            s[i][0]=o[i-1][0]*pa;
            o[i][0]=s[i-1][0]*pb;
        }
        for (i=1; i<=l; i++)
            for (j=1; j<l; j++)
            {
                s[i][j]=pa*o[i-1][j]+(1-pa)*o[i][j-1];
                o[i][j]=pb*s[i-1][j]+(1-pb)*s[i][j-1];
            }
        printf("%.1f\n",50*(s[l][l-1]+o[l][l-1]));
    }
    return 0;
}


