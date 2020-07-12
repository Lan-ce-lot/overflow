#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,len1,len2;
int next1[1000001];
char s1[1000001];
char s2[1000001];
inline void get_next() //���next���� 
{ //next�����Ǵ� S[0��i-1]ǰ�Ӵ� ��ǰ׺��׺���ֵ
    int t1=0,t2;
    next1[0]=t2=-1;
    while(t1<len2) 
        if(t2==-1 || s2[t1]==s2[t2]) //������KMP��ƥ�� 
            next1[++t1]=++t2;
        else t2=next1[t2];//ʧ�� 
} 
inline void KMP() //KMP 
{ 
    int t1=0,t2=0;//��0λ��ʼƥ�� 
    while(t1<len1) //�ٽ�ֵ 
    { 
        if(t2==-1 || s1[t1]==s2[t2]) //ƥ��ɹ������� 
            t1++,t2++;
        else t2=next1[t2]; //ʧ�� 
        if(t2==len2) printf("%d\n",t1-len2+1),t2=next1[t2];//t2==lenn2ʱ��ƥ��ɹ���t1-len2+1��Ϊ��һ����ĸ��λ�� 
    } //ƥ��ɹ���t2��Ϊnext[t2] 
} 

int KMP_Count(char x[], int m, char y[], int n) //x ��ģʽ����y ������
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
        printf("%d ",next1[i]);//���next���� 
    return 0;
}
