#include "algorithm"
#include "iostream"
#include "vector"
#include "string"
using namespace std;
struct node
{
	string name;
	int height;
};
vector<node> student;
bool cmp(node a,node b){
	return a.height!=b.height? a.height>b.height:a.name<b.name;
}
int main(){
	int n,k,m,j,i;
	scanf("%d %d",&n,&k);
	student.resize(n);
	for (i=0;i<n;i++)
	{
		cin>>student[i].name>>student[i].height;
	}
	//������ߡ������Ӵ�С����
	sort(student.begin(),student.end(),cmp);
	int t = 0, row = k;
	while(row) {
		if(row == k)
			m = n - n / k * (k - 1);//���ʣ����һ��
		else
			m = n / k;
		vector<string> stemp(m);
		stemp[m / 2] = student[t].name;//��ߵ���λͬѧ
		// ���һ��
		j = m / 2 - 1;
		for(i = t + 1; i < t + m; i = i + 2)
			stemp[j--] = student[i].name;
		// �ұ�һ��
		j = m / 2 + 1;
		for(i = t + 2; i < t + m; i = i + 2)
			stemp[j++] = student[i].name;
		// �����ǰ��
		cout << stemp[0];
		for(i = 1; i < m; i++) cout << " " << stemp[i];
		cout << endl;
		t = t + m;
		row--;
	}
	return 0;
}
