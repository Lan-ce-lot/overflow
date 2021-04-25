#include <bits/stdc++.h>
using namespace std;
int a,b,x,xor1,xor2,n;
int main()
{
	while(cin>>x){
		n++;
		b+=x;
		a+=n;
		xor1^=n;
		xor2^=x;
	}
	int k=abs(a-b);
	int xr,xc;
	int c=xor1^xor2;
	for(int i=1;i+k<=n;i++){
		if((i^(i+k))==c) {
			xr=i;
			xc=i+k;
		}
	}
	if(a<b) cout<<xr<<' '<<xc;
	else cout<<xc<<' '<<xr;
}

