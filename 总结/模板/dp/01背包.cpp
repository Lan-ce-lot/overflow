//��⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ���� 
#include <iostream>
#include<cstring>
using namespace std;
const int nmax=1000;
 
int v[nmax];//v[i]��ʾ��i����Ʒ�ļ�ֵvalue 
int w[nmax];//w[i]��ʾ��i����Ʒ������weight 
int dp[nmax];//�ܼ�ֵ 
int n,m;//n��ʾ��Ʒ������m��ʾ��������
 
int main() {//һά����ʵ�ֵ�01����ģ�� 
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>w[i]>>v[i];
		}
		for(int i=0;i<n;i++){//����n����Ʒ 
			for(int j=m;j>=0;j--){//01�������� �������
			  if(j>=w[i]){
			  	dp[j]=max(dp[j],(dp[j-w[i]]+v[i]));
			  }//��i�����岻ѡ��dp[j]=dp[j];
			   //��i��������ѡ	dp[j]=dp[j-w[i]]+v[i]
			} 
		}
		cout<<dp[m]<<endl;
	}
	
	return 0;
}
