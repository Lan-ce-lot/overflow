#include<stdio.h>
#include<iostream>
#include<assert.h>

typedef int Datatype;

typedef struct LinkList
{
    Datatype data;
    struct LinkList *next;
} List, *pList;

pList linshi(Datatype d)//创建一个临时变量
{
    pList tmp = NULL;
    tmp = (pList)malloc(sizeof(List));
    if (tmp == NULL)
    {
        perror("malloc()");
        exit(EXIT_FAILURE);
    }
    tmp->data = d;
    tmp->next = NULL;
}

void InintLinkList(pList *ppList)//初始化链表
{
    assert(ppList);
    *ppList = NULL;
}

void PushFront(pList *pplist, Datatype d)//从前插入节点
{
    assert(pplist);
    //空链表
    if (*pplist == NULL)
    {
        pList tmp = linshi(d);
        *pplist = tmp;
    }
    //非空链表
    else
    {
        pList cur = *pplist;
        pList tmp = linshi(d);
        tmp->next = *pplist;
        *pplist = tmp;
    }
}
void PopFront(pList *pplist)//从前删除节点
{
    assert(pplist);
    //非空链表
    if (*pplist != NULL)
    {
        pList cur = *pplist;
        *pplist = cur->next;
        free(cur);
    }
    //空链表
    else
    {
        return;
    }
}

void PushBack(pList *pplist, Datatype d)//从后插入节点
{
    assert(pplist);

    //空链表
    if (*pplist == NULL)
    {
        pList tmp = linshi(d);
        *pplist = tmp;
        return;
    }

    //非空链表
    pList cur = *pplist;
    pList tmp = linshi(d);
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = tmp;
}
void PopBack(pList *pplist)//从后删除节点
{
    assert(pplist);
    //空链表
    if (*pplist == NULL)
    {
        return;
    }
    //非空链表
    else
    {
        pList cur = *pplist;
        cur = cur->next;
        if (cur->next == NULL)
        {
            *pplist = NULL;
            free(cur);
        }
        else
        {
            pList del = *pplist;
            while (cur->next != NULL)
            {
                del = cur;
                cur = cur->next;
            }
            del->next = NULL;
            free(cur);
        }

    }
}

void Display(pList pplist)//打印链表
{
    pList cur = pplist;
    while (cur != NULL)
    {
        printf("%d --> ", cur->data);
        cur = cur->next;
    }
    printf("over\n");
}

pList Find(pList pplist, Datatype d)//查询相应数据
{
    if (pplist == NULL)
    {
        return NULL;
    }
    pList cur = pplist;
    while (cur != NULL)
    {
        if (cur->data == d)
        {
            return cur;
        }
        cur = cur->next;
    }
    return cur;
}

void Remove(pList *pplist, Datatype d)//删除
{
    assert(pplist);
    if (*pplist == NULL)
    {
        return;
    }
    else
    {
        pList cur = *pplist;
        while (Find(*pplist, d) != NULL && cur != NULL)
        {
            if (cur->data == d)
            {
                pList tmp = cur->next;
                cur->data = cur->next->data;
                cur->next = cur->next->next;
                free(tmp);
                return;
            }
            cur = cur->next;
        }
    }
}
void RemoveAll(pList *pplist, Datatype d)//删除所有
{
    assert(pplist);
    if (*pplist == NULL)
    {
        return;
    }
    else
    {
        pList cur = *pplist;
        while (Find(*pplist, d) != NULL && cur != NULL)
        {
            if (cur->data == d)
            {
                pList tmp = cur->next;
                cur->data = cur->next->data;
                cur->next = cur->next->next;
                free(tmp);
            }
            cur = cur->next;
        }
    }
}

void Insert(pList *pplist, int pos, Datatype d)//指定节点插入
{
    assert(pplist);
    //空链表
    if (*pplist == NULL)
    {
        pList tmp = linshi(d);
        *pplist = tmp;
        return;
    }
    //非空链表
    else
    {
        pList cur = *pplist;
        pos = pos - 1;
        pList tmp = linshi(d);
        while (pos-- && cur->next != NULL)
        {
            cur = cur->next;
        }
        if (pos > 0)
        {
            cur->next = tmp;
            tmp->data = d;
            tmp->next = NULL;
            return;
        }
        tmp->data = cur->data;
        cur->data = d;
        tmp->next = cur->next;
        cur->next = tmp;
    }
}
void Insert_Remove(pList *pplist, int pos)//指定节点删除
{
    assert(pplist);
    //空链表
    if (*pplist == NULL)
    {
        return;
    }
    //非空链表
    else
    {
        pList cur = *pplist;
        pList tmp = *pplist;
        pos = pos - 1;
        while (pos-- && cur->next != NULL)
        {
            cur = cur->next;
        }
        if (pos != 0)
        {
            pList del = *pplist;
            while (tmp->next != NULL)
            {
                del = tmp;
                tmp = tmp->next;
            }
            del->next = NULL;
            free(cur);
            return;
        }
        tmp = cur->next;
        cur->data = cur->next->data;
        cur->next = cur->next->next;
        free(tmp);
    }
}

pList Reverse(pList *pplist)//逆序
{
    assert(pplist);
    pList cur = *pplist;
    pList head = cur->next;
    pList newhead = NULL;
    head = cur->next;
    cur->next = NULL;
    newhead = cur;
    while (head != NULL)
    {
        cur = head;
        head = cur->next;
        cur->next = newhead;
        newhead = cur;
    }
    return newhead;
}
void Sort(pList *pplist)//排序  从小到大
{
    assert(pplist);
    pList cur = *pplist;
    int count = 0;
    int i, j;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    cur = *pplist;
    for (i = 0; i < count - 1; i++)
    {
        cur = *pplist;
        for (j = 0; j < count - 2 - i; j++)
        {
            if (cur->data > cur->next->data)
            {
                Datatype tmp;
                tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
            }
            cur = cur->next;
        }
    }

}

int main()
{
    pList head;
    InintLinkList(&head);

    /*PushFront(&head, 1);
    PushFront(&head, 2);
    PushFront(&head, 3);
    PushFront(&head, 4);
    PushFront(&head, 5);
    PushFront(&head, 6);
    Display(head);*/
    //PopFront(&head);
    //PopFront(&head);
    //PopFront(&head);
    //Display(head);

    //PushBack(&head, 1);
    //PushBack(&head, 2);
    //PushBack(&head, 7);
    //PushBack(&head, 4);
    //PushBack(&head, 7);
    //PushBack(&head, 6);
    //PushBack(&head, 7);
    //PushBack(&head, 8);
    //PushBack(&head, 9);
    //Display(head);
    //PopBack(&head);
    //PopBack(&head);
    //PopBack(&head);

    //pList ret = Find(head, 11);
    //if (ret == NULL)
    //{
    // printf("没找到！\n");
    //}
    //else
    //{
    // printf("找到了！\n");
    //}
    //Remove(&head, 7);
    //RemoveAll(&head, 7);
    //Insert(&head, 2, 11);
    //Insert_Remove(&head, 13);
    /*pList tmp = Reverse(&head);
    Display(tmp);*/
    //Sort(&head);
    Display(head);

    // system("pause");
    return 0;
}
