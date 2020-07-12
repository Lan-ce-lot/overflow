#include<iostream>
using namespace std;
typedef char elemtype;
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
int main(){
	elemtype a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	reverse1(a,0,n-1);//±ÕÇø¼ä 
	for(int i=0;i<n;++i){
		cout<<a[i]<<' ';
	}
	return 0;
} 
//5
//1 3
//1 2 3 4 5
//1 4 3 2 5
//5
//1 3
//a b c d e
//a d c b e

