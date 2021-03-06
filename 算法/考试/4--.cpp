/*
对于N >= 5，由于提出了一个5，因此需要一个2与之配成10，即将尾数除以2

*/ 
#include<bits/stdc++.h>
using namespace std;
string s;
int t,ans[20] = {1,1,2,6,4, 2, 2,4,2,8, 4, 4,8,4,6, 8, 8,6,8,2},A[2021];
//				 1,1,2,6,4, 2, 2,4,2,8, 8, 8,6,8,2, 8, 8,6,8,2
//				 1,1,2,6,4, 4, 4,8,4,6, 6, 6 2 6 4  
//				 2/2=6,4/2=2,6/2=8,8/2=4
int main(){
	scanf("%d", &t);
    while(t--){
		cin >> s;
		int l = s.size(),tmp=1;
		if(l == 1){
		    printf("%d\n",ans[s[0]-'0']);
		    continue;
		}
		for(int i = 0;i < l;i++)
		    A[i] = s[l-1-i] - '0';
		while(l){
		    tmp = tmp*ans[A[1]%2*10 + A[0]]%5;//求尾数！
		    for(int c = 0,i = l-1;i >= 0;i--){
		        c = c*10 + A[i],A[i] = c/5,c%=5;// 高精度除法 /5 
		    }
			l-=!A[l-1];
		}
        printf("%d\n",tmp+tmp%2*5);//加上遇到的2的个数
    }
} 
