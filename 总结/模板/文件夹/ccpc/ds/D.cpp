#include<bits/stdc++.h>
using namespace std;

int _,p,__;
double dp[1010];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&p);
		double prob=0.01*p;
		dp[200]=1/prob;
		for (int i=199;i>=1;i--) {
			double qrob=0.005*i;
			dp[i]=1+prob*(1-qrob)*dp[min(i+4,200)]+(1-prob)*dp[min(i+3,200)];
		}
		printf("Case %d: %.10f\n",++__,dp[4]);
	}
}
