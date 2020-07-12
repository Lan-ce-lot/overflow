#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	int i,j;
	int a[100][100];
	while(~scanf("%d",&n)&&n){
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				a[i][j]=1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=2;j<=i-1;j++){
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				if(i==1||j==i){
					printf("%d\n",a[i][j]);
				}else{
					printf("%d ",a[i][j]);
				}
			}
		}
		printf("\n");
	}
}

