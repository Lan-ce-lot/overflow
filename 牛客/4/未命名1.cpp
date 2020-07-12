#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int v[12][12]={0};
char f[4][2]={0,1,1,0,0,-1,-1,0};
char s[5]="RDLU";
int n,m;
int flag=0;
void dfs(int x,int y,string d){
    if(flag) return;
    if(d.size()==n*m&&x==0&&y==0){
        cout<<d;
        flag=1;
         
        return;
    }
    for(int i=0;i<4;i++){
     
        int x1=x+f[i][0];
        int y1=y+f[i][1];
         
        if(x1>=0&&y1>=0&&x1<n&&y1<m&&v[x1][y1]==0){
         
            v[x1][y1]=1;
            dfs(x1,y1,d+s[i]);
            v[x1][y1]=0;
        }
    }
}
int main(){
 
cin>>n>>m;
if(n%2&&m%2){
    flag=0;
}else
 dfs(0,0,"");
 if(flag==0){
    cout<<"-1";
 }
}
