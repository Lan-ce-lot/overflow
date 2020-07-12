#include<bits/stdc++.h>
using namespace std;
int getTime(char s[]){
    if(strcmp(s,"Beijing")==0)return 8;
    else if(strcmp(s,"Washington")==0)return -5;
    else if(strcmp(s,"London")==0)return 0;
    else return 3;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;++cs){
        int hour,minute;
        char s[20];
        scanf("%d%*c%d%s",&hour,&minute,s);
        hour%=12;
        if(strcmp(s,"PM")==0)hour+=12;
        char s1[20],s2[20];
        scanf("%s%s",s1,s2);
        hour+=getTime(s2)-getTime(s1);

        //printf("hour=%d\n",hour);

        printf("Case %d: ",cs);
        if(hour<0){
            printf("Yesterday ");
            hour+=24;
        }
        else if(hour<24)printf("Today ");
        else{
            printf("Tomorrow ");
            hour-=24;
        }
        if(hour<12)printf("%d",hour?hour:12);
        else printf("%d",hour-12?hour-12:12);
        printf(":%02d ",minute);
        if(hour<12)puts("AM");
        else puts("PM");
    }
}
