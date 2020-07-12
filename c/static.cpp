#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int func(int a, int b) 
{ static int m=0, i=2; 
  i+=m+1; 
  m=i+a+b; 
  return m; 
} 
int main( ) 
{ 
int k=4, m=1, p; 
p=func(k,m);
printf("%d",p); 
p=func(k,m);
printf("%d \n",p); 
} 

