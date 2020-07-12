#include <iostream>
using namespace std;
int main()
{
    char ch1 = '0';//48
    char ch2 = 'a';//97
    char ch3 = 'A';//65
    char ch4 = 'c';//99
    printf("%c的ASCII值为：%d\n", ch1, (int)ch1);//0
    printf("%c的ASCII值为：%d\n", ch2, (int)ch2);//a
    printf("%c的ASCII值为：%d\n", ch3, (int)ch3);//A
    printf("%c的ASCII值为：%d\n", ch4, (int)ch4);//c

    printf("%c-%c的差值为：%d\n", ch2, ch1, ch2-ch1);//a-0
    printf("%c-%c的差值值为：%d\n", ch2, ch2, (int)(ch2-ch2));//a-a
    printf("%c-%c的差值值为：%d\n", ch4, ch2, (int)(ch4-ch2));//c-a

    // a b c d e
    printf("字符c的ASCII值：%d\n", ('a'+2));
    printf("字符z的ASCII值：%d", ('a'+25));
    return 0;
}