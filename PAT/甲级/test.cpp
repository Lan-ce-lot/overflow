
#include<stdio.h>
using namespace std;
bool isPrime(int num1){//???????
 if(num1 < 2) return false;
 if(num1 == 2 || num1 == 3)return true;
 for(int i = 2; i * i <= num1; i ++){
  if(num1 % i == 0)return false;
 }
 return true;
}
int rev_num(int num1,int radix){//????radix?????(?????10???)
 int num2 = 0;
 while(num1){
  num2 *= radix;
  num2 += num1 % radix;
  num1 /= radix;
 }
 return num2;
}
int main(void){
 int n,d;
 while(scanf("%d",&n) != EOF){
  if(n < 0) break;//???????????
  scanf("%d",&d);
  int n_rev;
  n_rev = rev_num(n,d);
  if(isPrime(n) == true && isPrime(n_rev) == true)      //????????????
   puts("Yes");
  else
   puts("No");
 }
 return 0;
}
