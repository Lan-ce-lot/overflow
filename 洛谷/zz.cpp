#include<iostream>
#include<iostream>
using namespace std;
int main()
{
    int v=0;//�жϱ�־
    double A,B,C;
    int  a,b,c;
    int m,t,flag;
    cin>>A>>B>>C;
    int n[9];
    if(a<b&&b<c)
    {
        for(int i=123; i<1000*A/C; i++)
        {
            int n[9]= {0};
            t=0;
            a=i;
            b=B/A*i;
            c=C/A*i;
            n[2]=a%10;//��λ
            n[0]=a/100;//��λ
            n[1]=(a/10)%10;//ʮλ
            n[5]=b%10;
            n[3]=b/100;
            n[4]=(b/10)%10;
            n[8]=c%10;
            n[6]=c/100;
            n[7]=(c/10)%10;
            /*	s[a/100]++;
            	s[(a-a/100*100)/10]++;
            	s[a%10]++;//��a
            	s[b/100]++;
            	s[(b-b/100*100)/10]++;
            	s[b%10]++;//��b
            	s[c/100]++;
            	s[(c-c/100*100)/10]++;
            	s[c%10]++;//��c
            	*/
            for(m=0; m<9; m++)
            {
                for(int k=m+1; k<8; k++)
                    if(n[m]==n[k])
                    {
                        t=1;
                        break;
                    }
            }
            if(t==0)
            {
                printf("%d %d %d\n",a,b,c);
                flag++;
            }
        }
        if(flag==0)
        {
            cout<<"No!!!"<<endl;
        }
        else
            cout<<" No!!!"<<endl;
        return 0;
    }
}
