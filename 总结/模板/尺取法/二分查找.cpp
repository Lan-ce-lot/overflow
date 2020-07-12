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
const int maxn=1005;
int binarySearch(int* nums,int numSize,int target)
{
    int left=0;
    int right=numSize-1;
    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(target==nums[mid])return mid;
        else if(target<nums[mid])
        {
            right=mid-1;
        }
        else
        {

            left=mid+1;
        }
    }
    return -1;
}

int a[maxn];
int main()
{
    int i=0,t=0,n=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];

    }


    while(cin>>t)
        cout<<binarySearch(a,i,t)<<' '<<binary_search(a,a+i,t)<<' '<<lower_bound(a,a+i,t)<<' '<<upper_bound(a,a+i,t)<<endl;
    return 0;
}
