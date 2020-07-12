/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <unistd.h>
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

int main()
{ 
    pid_t fpid; //fpid��ʾfork�������ص�ֵ  
    int count=0;  
    fpid=fork();   //���µ���丸���̺��ӽ��̶���ִ�У���Ҫ��pid������
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        printf("i am the child process, my process id is %d/n",getpid());   
        printf("���ǵ��Ķ���/n");//��ĳЩ����˵���Ŀ��Ÿ�ֱ�ס�  
        count++;  
    }  
    else {  
        printf("i am the parent process, my process id is %d/n",getpid());   
        printf("���Ǻ�������/n");  
        count++;  
    }  
    printf("ͳ�ƽ����: %d/n",count);  
    return 0;  
//    for(;;)
//        fork();

    return 0;
}

