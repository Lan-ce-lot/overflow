#include <bits/stdc++.h>

using namespace std;
set<string> s;
int a[10]={1,1,1,0,0,0,0,0,0,0};
int main(){
    int n=10;
	int ans=0,count=0;
	sort(a,a+n);
        do{


            for(int i=0;i<n;i++)
            {
            	printf("%d ",a[i]);
			}
            ans++;
            puts("");
            count++;
        }while(next_permutation(a,a+n));
    cout<<count<<endl;
    return 0;
}
