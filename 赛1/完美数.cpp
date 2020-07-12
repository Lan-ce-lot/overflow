#include<bits/stdc++.h> 

using namespace std;
int a[1000];
bool checkPerfectNumber(int num) {
    if(num == 1) return false;
    int n = sqrt(num);
    int ans = 1;
    for(int i = 2;i <= n;i++){
        if(num % i == 0){
            ans += i + num / i;
        }
    }
    return ans == num;
}

int main()

{
	int i=6;int z=0;
	for(i=6;i<10000000;i++)
	{
		if(i%10!=8&&i%10!=6)
		{
			continue;
		}
		int ans=1;
		for(int j=2;j*2<=i;j++)
		{
			if(i%j==0&&i/j>=j)
			{
				ans+=j+i/j;
				if(i/j<j)
				{
					break;
				}
			}	
		}
		if(ans==i)
			cout<<ans<<endl;
	}
	return 0;

}
