//结构体

struct node

{

         int data;

         char sex;

}s1,s2;                         //-------------变量s1,s2

 

typedef struct node

{

         int data;

         char sex;

}SS;                           //-------------类型名SS

 

typedef 存在类型名 自定义类型名

 

结构体指针

typedef struct node

{

         int data;

         struct node* next;           //-------------定义的同时使用

};*pointer;

等价于

typedef struct node* pointer

{

         int data;

         pointer next;               //-------------定义的同时使用

};

等价于

struct node

{

         int data;

         struct node *next;  

};

typedef struct node* pointer;//----------常见的定义方式
