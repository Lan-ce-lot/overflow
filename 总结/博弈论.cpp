#include<iostream>
int n,a,x,i;
int main()
{
    std::cin>>n>>a;
    for(;i<n;i++)std::cin>>a,x^=a;
    puts(x?"YES":"NO");
}
