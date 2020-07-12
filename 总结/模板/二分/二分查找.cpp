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

    while()
    int l=1,r=i;
		while(l<=r){//二分找左边最小值
			int mid=(l+r)>>1;
			if(a[mid]<w) r=mid-1;
			else l=mid+1;
		}


    return 0;
}
