#include<iostream>
#include<iomanip>
#include<cmath>
#include<map>
#include<string>
#include<algorithm>
#include<string.h>
 
using namespace std;
char str[100005];
int main()
{
    int len,index=1;
    cin>>str;
    len=strlen(str);
    for(int i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            index=0;
            break;
        }
    }
    if(index)
    cout<<"Yes"<<endl;
    else
    {
         
        int index2=0,index3=0;
         
        for(int i=0,j=0,len2=len-1;i<len/2+1;i++,j++,len2--)
        {
            if(str[j]!=str[len2])
            {  
                index2++;
                len2++;
            }
        }
        for(int i=0,j=0,len2=len-1;i<len/2+1;i++,j++,len2--)
        {
            if(str[j]!=str[len2])
            {  
                index3++;
                j--;
            }
        }
        if(index2==1||index3==1)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
 
}
