#include <iostream>
#include <malloc.h>

using namespace std;

//#define OK        1
//#define OVERFLOW -2
//#define ERROR     0
//typedef char TElemType;


#define OK              1
#define ERROR           0
#define OVERFLOW       -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
typedef int Status;
//typedef char TElemType;
//typedef struct BiTNode
//{
//    TElemType data;
//    struct BiTNode *lchild,*rchild;
//}BiTNode, *BiTree,*SElemType;
typedef char SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
    S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}
Status StackEmpty(SqStack S)
{
    return(S.top==S.base);
}
Status GetTop(SqStack S,SElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    e=*(S.top-1);
    return OK;
}
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base)
            exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}
Status Pop(SqStack &S,SElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    e=*--S.top;
    return OK;
}
Status ClearStack(SqStack &S){
	S.top = S.base;
}
