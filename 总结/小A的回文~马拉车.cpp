#include<bits/stdc++.h>
using namespace std;
#define mxn 5005
string Manacher(string s)
{
    string res="$#";
    for(int i=0;i<s.size();++i)
    {
        res+=s[i];
        res+="#";
    }
    vector<int> P(res.size(),0);
    int mi=0,right=0;   //miΪ�����Ĵ���Ӧ�����ĵ㣬rightΪ�û��Ĵ��ܴﵽ�����Ҷ˵�ֵ
    int maxLen=0,maxPoint=0;    //maxLenΪ�����Ĵ��ĳ��ȣ�maxPointΪ��¼���ĵ�
    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     //�ؼ��䣬���ж��������ϸ����
        while(res[i+P[i]]==res[i-P[i]])
           ++P[i];
        if(right<i+P[i])    //����֮ǰ�����Ҷˣ���ı����ĵ�Ͷ�Ӧ�����Ҷ�
        {
            right=i+P[i];
            mi=i;
        }
        if(maxLen<P[i])     //���������Ĵ��ĳ��ȣ������´�ʱ�ĵ�
        {
            maxLen=P[i];
            maxPoint=i;
        }
    }
    return s.substr((maxPoint-maxLen)/2,maxLen-1);
}
 
char s[mxn];
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    string ss;
    for(int o=0;o<2;++o)
    for(int i=0;i<len;++i) ss.push_back(s[i]);
    int res = Manacher(ss).size();
    cout<<min(res,len)<<endl;
    return 0;
}
