// ��ģ�������(line 3)����ģ��ʵ���������ģ����
// ��ģ��������д��   template <class T> class ����{}
template <class T> class ArrayStack
{
public:
    ArrayStack();
    ArrayStack(int count);
    ~ArrayStack();
    void push(T data);     //��ջ
    T pop();      //��ջ����ɾ��ջ��Ԫ��
    T peek();     //����ջ��Ԫ�أ���ɾ��ջ��Ԫ�أ�ջ��ָ�벻��
    int stackSize();
    int stackMaxSize();

private:
    int flag;       //ջ����ǩ��ָ��ջ��
    int count ;     //ջ������
    T *array;       //ָ��
};
