#include <cstdio>

#include <iostream>

#include <climits>

#include <algorithm>

#include <vector>

using namespace std;

vector<pair<int,int>>a;

template<typename tfunc>

pair<double,int> Calc(int id,tfunc f){

vector<double> v;

int i;

for(i=0; i<a.size(); ++i){

 v.push_back(a[i].second / f(a[i].first));

}

double sum=0.0,variance=0.0;

for (double x:v){sum += x;}

sum/=a.size();

for (double x:v){

variance += (x/sum-1)*(x/sum-1);

}

return make_pair(variance,id);

}

int main(){

int n=0,i;

while(scanf("%d",&n),n){

a.resize(n);

for(i=0;i<n;++i){

scanf("%d",&a[i].second);

}

for(i=0;i<n;++i){

scanf("%d",&a[i].second);

}

sort(a.begin(),a.end());

pair<double,int>

ans(numeric_limits<double>::infinity(),0);

ans= min(ans,Calc(1,[](double n){return n;}));

ans= min(ans,Calc(2,[](double n){return n*log(n);}));

ans= min(ans,Calc(3,[](double n){return n*n;}));

ans= min(ans,Calc(4,[](double n){return n*n*n;}));

ans= min(ans,Calc(5,[](double n){return pow(2,n);}));

ans= min(ans,Calc(6,[](double n){

if(n<20){

double r=1.0;

for(int i=1;i<=n+0.2;++i)

    r *=i;

return r;

}

return sqrt(2*acos(-1)*n)*pow(n/exp(1),n)*exp(1.0/12/n-1/360/n/n/n);

}));

printf("%d\n",ans.second);

}

}
