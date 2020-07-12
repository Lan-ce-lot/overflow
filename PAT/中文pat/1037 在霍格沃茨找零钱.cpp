#include<bits/stdc++.h>
using namespace std;
int main()
{
	int Galleon,Sickle,Knut,Galleon1,Sickle1,Knut1,a_Galleon,a_Sickle,a_Knut,flag=0;
	scanf("%d.%d.%d",&Galleon,&Sickle,&Knut);
	scanf("%d.%d.%d",&Galleon1,&Sickle1,&Knut1);
	if(Galleon>Galleon1||Galleon==Galleon1&&Sickle>Sickle1||Galleon==Galleon1&&Sickle==Sickle1&&Knut>Knut1)
	{
		int a;
		a=Galleon;
		Galleon=Galleon1;
		Galleon1=a;
		a=Sickle;
		Sickle=Sickle1;
		Sickle1=a;		
		a=Knut;
		Knut=Knut1;
		Knut1=a;		
		flag=1;
	}
	if(Knut>Knut1)
	{
		Knut1 += 29;
		Sickle1 --;
	}
	a_Knut = Knut1 - Knut;
	if(Sickle > Sickle1)
	{
		Sickle1 += 17;
		Galleon1 --;
	}
	a_Sickle = 	Sickle1	- Sickle;
	a_Galleon = Galleon1 - Galleon;
//	Galleon.Sickle.Knut	
if(flag)
{
	printf("-%d.%d.%d\n",a_Galleon,a_Sickle,a_Knut);		
}
else
	printf("%d.%d.%d\n",a_Galleon,a_Sickle,a_Knut);				
	

	return 0;
}
