//�ṹ��

struct node

{

         int data;

         char sex;

}s1,s2;                         //-------------����s1,s2

 

typedef struct node

{

         int data;

         char sex;

}SS;                           //-------------������SS

 

typedef ���������� �Զ���������

 

�ṹ��ָ��

typedef struct node

{

         int data;

         struct node* next;           //-------------�����ͬʱʹ��

};*pointer;

�ȼ���

typedef struct node* pointer

{

         int data;

         pointer next;               //-------------�����ͬʱʹ��

};

�ȼ���

struct node

{

         int data;

         struct node *next;  

};

typedef struct node* pointer;//----------�����Ķ��巽ʽ
