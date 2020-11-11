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
/*判断是否是关键字*/
int isKey(char searchchar[])  /*判断单词是保留字还是标识符*/
{
	int i = 0;
	int p;
		for (i = 0; i <= 5; i++)
		{
			if (strcmp(keyWords[i], searchchar) == 0)
			{
				p = i + 1;    /*是保留字则p为非0且不重复的整数*/
				break;
			}
			else p = 0;             /*不是保留字则用于返回的p=0*/
		}
		return p;
	
}
/*第一个是数字的处理函数*/
char digitScan(char buffer)
{
	int i = -1;
	char digittp[20];
	if (buffer == '0')  /* 0开头的数字可能是10进制的0和八进制或者16进制*/
	{
		digittp[++i] = buffer;
		buffer = fgetc(fp);
		if (buffer == 'x' || buffer=='X')
		{
			while ((isdigit(buffer)) || isalpha(buffer))//16进制 
			{
				digittp[++i] = buffer;
				buffer = fgetc(fp);
			}
			digittp[i + 1] = '\0';
			printf("<3，%s>\n", digittp + 2);
		}
		else if (isdigit(buffer))
		{
			while ((isdigit(buffer)))//8进制 
			{
				digittp[++i] = buffer;
				buffer = fgetc(fp);
			}
			digittp[i + 1] = '\0';
			printf("<2 ,%s>\n", digittp + 1);
		}
		else             //十进制 
		{
			digittp[i + 1] = '\0';
			printf("<1,%s>\n", digittp + 2);
		}

	}
	else                   /* 不以0开头的都是10进制*/
	{
		while ((isdigit(buffer)) || buffer == '.' || buffer == 'e')//1.小数点  2.科学计数法
		{
			digittp[++i] = buffer;
			buffer = fgetc(fp);
		}
		digittp[i + 1] = '\0';
		printf("<1，%s>\n", digittp);
		
	}

	return(buffer);
}

	
/*第一个是字母的处理函数*/
char  alphaScan(char cbuffer)
{
	int   type;   /*保留字数组中的位置*/
	int   i = -1;
	char  alphatp[20];
	while ((isalpha(cbuffer)) || (isdigit(cbuffer)) || cbuffer == '_')
	{
		alphatp[++i] = cbuffer;
		cbuffer = fgetc(fp);
	}  /*读一个完整的单词放入alphatp数组中*/
	alphatp[i + 1] = '\0';
	type = isKey(alphatp);/*对此单词调用isKey函数判断类型*/
	if (type != 0)
	{
		printf("<%s, ->\n", alphatp);
	}
	else
	{
		printf("<0，%s >\n", alphatp);
	}
	return(cbuffer);
}



/*其他字符的处理函数*/
char OtherScan(char buffer)
{
	char op[20];
	op[0] = buffer;
	op[1] = '\0';
	if(op[0]==',' || op[0]== ';' || op[0] == '(' || op[0] == ')' || op[0] == '{' || op[0] == '}')//界符
	{
		printf("<%s,->\n", op);
		buffer = fgetc(fp);
		return buffer;
	}
	if (op[0] == '*')  //乘方
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
		else   //乘法符号
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
				printf("<%s，19>\n",op); //注释
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
				printf("<%s，20>\n", op);//注释
				buffer = fgetc(fp);
				return buffer;
			}
		}
		else
		{
			printf("<%s , - >\n", op);  //除法
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

/*scan函数 */
char scan(char buffer)
{
	if (isalpha(cbuffer))  /*以字母开头的单词*/
	{
		cbuffer = alphaScan(cbuffer);
	}

	else if (isdigit(cbuffer)) /*以数字开头的单词*/
	{
		cbuffer = digitScan(cbuffer);
	}

	else
	{
		cbuffer = OtherScan(cbuffer);/*以其他字符开始的字符*/
	}
	return cbuffer;
}
int main()
{
	if ((fp = fopen("test.txt", "r")) == NULL)   /*只读方式打开一个文件*/
		printf("error");
	else
	{
		cbuffer = fgetc(fp);  /*fgetc( )函数：从磁盘文件读取一个字符*/
		while (cbuffer != EOF)
		{
			if (cbuffer == ' ' || cbuffer == '\n' || cbuffer == '\t')   /*掠过空格和回车符*/ /*17.tab键*/
				cbuffer = fgetc(fp);
			else
			{
				cbuffer = scan(cbuffer);  //进入查询函数
			}
		}
	}
	system("pause");
	return 0;
}
