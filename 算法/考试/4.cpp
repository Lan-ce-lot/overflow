//#include <bits/stdc++.h>
//using namespace std;
//string N;
//int t,ans[4]={6,2,4,8};
//long long n, num,c;
//int main(){
//    scanf("%d", &t);
//    while(t--){
//    	cin>>N;
//    	if(N.size()>19){
//    		printf("2\n");
//    		continue;
//		}else{
//			n = 0;
//			for (int i = 0; i < N.size(); i++) {
//				n*=10;
//				n+=N[i]-'0';
//			}
//		}
//        num=n;
//        c=0;
//        while(num){
//            if(num%5==2)c++;
//            else if(num%5==4)c+=2;
//            c+=num/5;
//            num/=5;
//        }
//        if(n>1)
//            printf("%d\n",ans[c%4]);
//        else printf("1\n");
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string N;
    long long num,n,c,ans[4]={6,2,4,8},t;
    cin>>t;
    while(t--){
         cin>>N;
         if(N.size()>18){
              cout<<8<<endl;
              continue;
          }else {
              n=0;
              for(int i=0;i<N.size();i++){
                  n*=10;
                   n+=N[i]-'0'; 
               }
          }
         num=n;
         c=0;
         while(num){
              if(num%5==2)c++;
              else if(num%5==4)c+=2;
              c+=num/5;
              num/=5;
          }
         if(n>1)cout<<ans[c%4]<<endl;
         else cout<<1<<endl;

    }

}
/*
x


*/
