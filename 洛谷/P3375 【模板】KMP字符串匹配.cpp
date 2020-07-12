#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,len1,len2;
int next1[1000001];
char s1[1000001];
char s2[1000001];
inline void get_next() //求出next数组 
{ //next数组是从 S[0到i-1]前子串 的前缀后缀最大值
    int t1=0,t2;
    next1[0]=t2=-1;
    while(t1<len2) 
        if(t2==-1 || s2[t1]==s2[t2]) //类似于KMP的匹配 
            next1[++t1]=++t2;
        else t2=next1[t2];//失配 
} 
inline void KMP() //KMP 
{ 
    int t1=0,t2=0;//从0位开始匹配 
    while(t1<len1) //临界值 
    { 
        if(t2==-1 || s1[t1]==s2[t2]) //匹配成功，继续 
            t1++,t2++;
        else t2=next1[t2]; //失配 
        if(t2==len2) printf("%d\n",t1-len2+1),t2=next1[t2];//t2==lenn2时，匹配成功；t1-len2+1即为第一个字母的位置 
    } //匹配成功后，t2置为next[t2] 
} 

int KMP_Count(char x[], int m, char y[], int n) //x 是模式串，y 是主串
{
    int i, j;
    int ans = 0;
    i = j = 0;
    while(i < n)
    {
        while(-1 != j && y[i] != x[j])j = next1[j];
        i++;
        j++;
        if(j >= m)
        {
            ans++;
            j = next1[j];
        }
    }
    return ans;
}

int main(){ 
    scanf("%s",s1);
    scanf("%s",s2);
    len1=strlen(s1);
    len2=strlen(s2);
    get_next();
    KMP();
    cout << KMP_Count(s2, len2, s1, len1);
    for(int i=1;i<=len2;++i) 
        printf("%d ",next1[i]);//输出next数组 
    return 0;
}
