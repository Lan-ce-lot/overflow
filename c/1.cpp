/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>

#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n;
char scan(char buffer);
FILE *fp; 
char cbuffer;
char keyWords[100][100] = {"then", "if", "else"};
/*�ж��Ƿ��ǹؼ���*/
int isKey(char searchchar[])  /*�жϵ����Ǳ����ֻ��Ǳ�ʶ��*/
{
	int i = 0;
	int p;
		for (i = 0; i <= 5; i++)
		{
			if (strcmp(keyWords[i], searchchar) == 0)
			{
				p = i + 1;    /*�Ǳ�������pΪ��0�Ҳ��ظ�������*/
				break;
			}
			else p = 0;             /*���Ǳ����������ڷ��ص�p=0*/
		}
		return p;
	
}
/*��һ�������ֵĴ�����*/
char digitScan(char buffer)
{
	int i = -1;
	char digittp[20];
	if (buffer == '0')  /* 0��ͷ�����ֿ�����10���Ƶ�0�Ͱ˽��ƻ���16����*/
	{
		digittp[++i] = buffer;
		buffer = fgetc(fp);
		if (buffer == 'x' || buffer=='X')
		{
			while ((isdigit(buffer)) || isalpha(buffer))//16���� 
			{
				digittp[++i] = buffer;
				buffer = fgetc(fp);
			}
			digittp[i + 1] = '\0';
			printf("<3��%s>\n", digittp + 2);
		}
		else if (isdigit(buffer))
		{
			while ((isdigit(buffer)))//8���� 
			{
				digittp[++i] = buffer;
				buffer = fgetc(fp);
			}
			digittp[i + 1] = '\0';
			printf("<2 ,%s>\n", digittp + 1);
		}
		else             //ʮ���� 
		{
			digittp[i + 1] = '\0';
			printf("<1,%s>\n", digittp + 2);
		}

	}
	else                   /* ����0��ͷ�Ķ���10����*/
	{
		while ((isdigit(buffer)) || buffer == '.' || buffer == 'e')//1.С����  2.��ѧ������
		{
			digittp[++i] = buffer;
			buffer = fgetc(fp);
		}
		digittp[i + 1] = '\0';
		printf("<1��%s>\n", digittp);
		
	}

	return(buffer);
}

	
/*��һ������ĸ�Ĵ�����*/
char  alphaScan(char cbuffer)
{
	int   type;   /*�����������е�λ��*/
	int   i = -1;
	char  alphatp[20];
	while ((isalpha(cbuffer)) || (isdigit(cbuffer)) || cbuffer == '_')
	{
		alphatp[++i] = cbuffer;
		cbuffer = fgetc(fp);
	}  /*��һ�������ĵ��ʷ���alphatp������*/
	alphatp[i + 1] = '\0';
	type = isKey(alphatp);/*�Դ˵��ʵ���isKey�����ж�����*/
	if (type != 0)
	{
		printf("<%s, ->\n", alphatp);
	}
	else
	{
		printf("<0��%s >\n", alphatp);
	}
	return(cbuffer);
}



/*�����ַ��Ĵ�����*/
char OtherScan(char buffer)
{
	char op[20];
	op[0] = buffer;
	op[1] = '\0';
	if(op[0]==',' || op[0]== ';' || op[0] == '(' || op[0] == ')' || op[0] == '{' || op[0] == '}')//���
	{
		printf("<%s,->\n", op);
		buffer = fgetc(fp);
		return buffer;
	}
	if (op[0] == '*')  //�˷�
	{
		buffer = fgetc(fp);
		op[1] = buffer;
		if (op[1] == '=')
		{
			op[2] = '\0';
			printf("<%s, - >\n", op);
			buffer = fgetc(fp);
			return buffer;
		}
		else   //�˷�����
		{
			op[1] = '\0';
			printf("<%s, - >\n", op);
			buffer = fgetc(fp);
			return buffer;
		}
	}
	if (op[0] == '/')
	{
		buffer = fgetc(fp);
		op[1] = buffer;
		if (op[1] == '=')
		{
			op[2] = '\0';
			printf("<%s , - >\n", op);
			buffer = fgetc(fp);
			return buffer;
		}
		else if (op[1] == '/' || op[1] == '*')
		{
			int i = 1;
			if (op[1] == '*')
			{
				while (op[i] != '/')
				{
					buffer = fgetc(fp);
					op[++i] = buffer;
				}
				op[i + 1] = '\0';
				printf("<%s��19>\n",op); //ע��
				buffer = fgetc(fp);
				return buffer;
			}
			else
			{
				while (op[i] != '\n')
				{
					buffer = fgetc(fp);
					op[++i] = buffer;
				}
				op[i] = '\0';
				printf("<%s��20>\n", op);//ע��
				buffer = fgetc(fp);
				return buffer;
			}
		}
		else
		{
			printf("<%s , - >\n", op);  //����
			buffer = fgetc(fp);
			return buffer; 
		}
	}

	if (op[0] == '=' || op[0] == '<' || op[0] == '>')
	{
		buffer = fgetc(fp);
		if (buffer == '=')
		{
			op[1] = buffer;
			op[2] = '\0';
			printf("<%s,->\n", op);
		}
		else
		{
			printf("<%s,- >\n", op);
		}
		
		return buffer;
	}
	if (op[0] == '+' || op[0] == '-')
	{
		printf("<%s,- >\n", op);
		buffer = fgetc(fp);
		return buffer;
	}

	return buffer;
}

/*scan���� */
char scan(char buffer)
{
	if (isalpha(cbuffer))  /*����ĸ��ͷ�ĵ���*/
	{
		cbuffer = alphaScan(cbuffer);
	}

	else if (isdigit(cbuffer)) /*�����ֿ�ͷ�ĵ���*/
	{
		cbuffer = digitScan(cbuffer);
	}

	else
	{
		cbuffer = OtherScan(cbuffer);/*�������ַ���ʼ���ַ�*/
	}
	return cbuffer;
}
int main()
{
	if ((fp = fopen("test.txt", "r")) == NULL)   /*ֻ����ʽ��һ���ļ�*/
		printf("error");
	else
	{
		cbuffer = fgetc(fp);  /*fgetc( )�������Ӵ����ļ���ȡһ���ַ�*/
		while (cbuffer != EOF)
		{
			if (cbuffer == ' ' || cbuffer == '\n' || cbuffer == '\t')   /*�ӹ��ո�ͻس���*/ /*17.tab��*/
				cbuffer = fgetc(fp);
			else
			{
				cbuffer = scan(cbuffer);  //�����ѯ����
			}
		}
	}
	system("pause");
	return 0;
}
