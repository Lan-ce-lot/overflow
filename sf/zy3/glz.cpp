#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
typedef vector<vector<int>> VC;
const double maxn=0x3fffffff;
void salesman_problem(int n,double &min,int t[],VC c){
	int p[n],i;
	double cost;
	for(i=0;i<n;i++){
		p[i]=i;
	}
	min=maxn;
	do{
		cost=0;
		for(i=0;i<n-1;i++){
			cost+=c[p[i]][p[i-1]];
		}
		cost+=c[p[n-1]][p[0]];
		if(cost<min){
			for(i=0;i<n-1;i++){
				t[i]=p[i];
				min=cost;
			}
		}
	}while(next_permutation(p,p+n));
}
#include <chrono>
#include <random>
unsigned seed1 =std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed1);

int main(){
	int n=1;
	while(n<=12){
		int path[100];
	double mincost;
	clock_t start,end;
	cout<<n<<"  ";
	VC c(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][j]=100+mt()%100;
		}
	}
	start=clock();
	salesman_problem(n,mincost,path,c);
	end=clock();
	cout<<(int)(end-start)*1000.0/CLOCKS_PER_SEC<<"(ms)"<<endl;
//	cout<<mincost<<endl;
//	for(int i=0;i<n-1;i++){
//		cout<<path[i]<<"->";
//	}
//	cout<<path[0]<<endl;
	n++;
	}
	
}
