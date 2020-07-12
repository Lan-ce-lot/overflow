#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=30005;
typedef int elemtype;
void reverse1(elemtype *a,int i,int j){
	elemtype c;
	while(i<j){
		c=a[i];
		a[i]=a[j];
		a[j]=c;
		i++;
		j--;
	}
}
//int main(){
//	elemtype a[100];
//	int n;
//	cin>>n;
//	for(int i=0;i<n;++i){
//		cin>>a[i];
//	}
//	reverse1(a,0,n-1);
//	for(int i=0;i<n;++i){
//		cout<<a[i]<<' ';
//	}
//	return 0;
//} 
int d[maxn], c[maxn], a[maxn], lenr = 1,lenl = 1;
int main()
{
	int n,max_r=0,max_l=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
    d[1] = a[1], c[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (d[lenr] <= a[i]) {
            d[++ lenr] = a[i], c[i] = lenr;
        } 
		else {
            int j = upper_bound(d + 1, d + lenr + 1, a[i]) - d;
            d[j] = a[i], c[i] = j;
        }
    }
    reverse1(a,1,n);
    d[1] = a[1], c[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (d[lenl] <= a[i]) {
            d[++ lenl] = a[i], c[i] = lenl;
        } 
		else {
            int j = upper_bound(d + 1, d + lenl + 1, a[i]) - d;
            d[j] = a[i], c[i] = j;
        }
    }   
	lenr =max(lenr,lenl);
	cout<<n-lenr<<endl;
    return 0;
}//10 2 1 1 1 3 2 1 1 1 2//9 2 1 1 1 1 3 3 3 2

//From - Milky Way
