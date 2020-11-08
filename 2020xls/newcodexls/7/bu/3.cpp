// Created by CAD
#include <bits/stdc++.h>
using namespace std;

char l[200][10],r[200][10];
const int maxn=26*26+26;
int ans[maxn];
int con1 = 0, con2 = 0, con3 = 0, con4 = 0;
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s = %s",l[i],r[i]);
    for(int t=0;t<26*maxn;++t)
        for(int i=0;i<n;++i)
            if(islower(r[i][0]))                        //A=a
                ans[l[i][0]-'A']|=1<<(r[i][0]-'a'), con1++;
            else if(!l[i][1]&&!r[i][1])                 //A=B
                ans[l[i][0]-'A']|=ans[r[i][0]-'A'], con2++;
            else if(l[i][1]=='.')                       //A.f=B
                for(int j=0;j<26;++j){
                    if(ans[l[i][0]-'A']>>j&1)
                        ans[26+j*26+l[i][2]-'a']|=ans[r[i][0]-'A'],con3++;
                }
            else                                        //A=B.f
                for(int j=0;j<26;++j)
                    if(ans[r[i][0]-'A']>>j&1)
                    {
//                    	cout << 1 << endl;
						con4++;
						cout << i << j<< r[i][0]-'A' << ' ' << (ans[r[i][0]-'A']>>j) << endl;
                    	ans[l[i][0]-'A']|=ans[26+j*26+r[i][2]-'a'];
					}
                        
    for(int i=0;i<26;++i){
//        cout<<char('A'+i)<<": ";
        cout << ans[i] << endl;
//        for(int j=0;j<26;++j)
//            if(ans[i]>>j&1) cout<<char('a'+j);
//        cout<<endl;
    }// 18251
	cout << con1 <<' ' << con2<< ' ' << con3 << ' ' << con4 << endl;
}
