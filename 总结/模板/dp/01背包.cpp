//求解将哪些物品装入背包可使价值总和最大 
#include <iostream>
#include<cstring>
using namespace std;
const int nmax=1000;
 
int v[nmax];//v[i]表示第i个物品的价值value 
int w[nmax];//w[i]表示第i个物品的重量weight 
int dp[nmax];//总价值 
int n,m;//n表示物品数量，m表示背包容量
 
int main() {//一维数组实现的01背包模板 
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>w[i]>>v[i];
		}
		for(int i=0;i<n;i++){//遍历n个物品 
			for(int j=m;j>=0;j--){//01背包容量 逆序遍历
			  if(j>=w[i]){
			  	dp[j]=max(dp[j],(dp[j-w[i]]+v[i]));
			  }//第i个物体不选，dp[j]=dp[j];
			   //第i个物体若选	dp[j]=dp[j-w[i]]+v[i]
			} 
		}
		cout<<dp[m]<<endl;
	}
	
	return 0;
}
