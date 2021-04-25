#include<bits/stdc++.h>
using namespace std;
//交换
set<int> S;
int coun = 0;
void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
 } 
 //全排列递归算法
void Perm(int list[] , int k ,int m) 
{
	//list 数组存放排列的数，K表示层 代表第几个数，m表示数组的长度
	if(k==m)
	{
		int tmp = 0;
		//K==m 表示到达最后一个数，不能再交换，最终的排列的数需要输出；
		for(int i=0 ;i<=m ;i++)
		 cout<<list[i], tmp *= 10, tmp+= list[i];
		 cout<<endl; 
		 coun++;
		 S.insert(tmp);
	 } 
	 else{
	 	for(int i=k;i<=m;i++)
	 	{
	 		swap(list[i],list[k]);
	 		Perm(list,k+1,m);
	 		// swap(list[i] , list[k]);
		 }
	 }
	 
}
int main(void)
{
   int a[]={1,2,3,4, 5, 6};
   int m=2;
   Perm(a,0,3);
   cout << coun << endl;
   cout << S.size() << endl;
	/*
0
0
2
12

  123
  132
  213
  231
  321
  312

2
12
72
504
*/
 } 
 /*
1234
1243
1423
1432


2143
2134
2314
2341


3124
3142
3412
3421








 
1234
1243
1423
1432
	1234
	1243
2143
2134
2314
2341
	2143
	2134
3124
3142
3412
3421
	3124
	3142
	2143
	2134
	2314
	2341
	2143
	2134
 */