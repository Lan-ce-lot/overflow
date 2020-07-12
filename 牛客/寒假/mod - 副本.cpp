#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
//int main()
//{
//    freopen("F:/Overflow/in.txt","r",stdin);
//	int n,k,r,l;
//	char str[200200];
//	int max1=-1;
//	scanf("%d%d", &n,&k);
//	scanf("%s", str);
//	r=-1;
//	l=0;
//int count1=0,count2=0;
//////把雍æȐ一*/
//for(l=0,r=0;r<n;r++)
//{
//	if(str[r]=='0')
//	count1++;
//	else
//	{
//		count2++;
//	}
//		while(count1>k)
//		{
//			if(str[l]=='0')
//			{
//				count1--;
//			}
//			else
//			count2--;
//			l++;
//		}
//		max1=max(max1,r-l+1);
// }
// 把不æȐ零*/
// count1=0;
// count2=0;
// for(r=0,l=0;r<n;r++)
// {
// 	if(str[r]=='0')
// 	count1++;
// 	else
// 	count2++;
// 	while(count2>k)
// 	{
// 		if(str[l]=='0')
// 		{
// 			count1--;
//		 }
//		 else
//		 count2--;
//		 l++;
//	 }
//	 max1=max(max1,r-l+1);
//  }
//  printf("%d\n", max1);
//}
const int maxn = 10000;
string str;
int n, c;
int p0[2][maxn];
int p1[2][maxn];
int t0 = 0, t1 = 0;
int main()
{
    cin >> n >> c;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            t0++;
            if (t0 == 1)
            {
                p0[0][] =
            }

        }
        else
        {

        }
    }
}
