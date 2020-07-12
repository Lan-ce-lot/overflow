/*************************************************************************
 > File Name: array_queue.h
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-12
 > Desc:    
 ************************************************************************/
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct _array_queue
{
	int size;/*���еĴ�С*/
	int num; /*��ǰ�洢���ݵĴ�С*/
	int head;/*���е�ͷ*/
	int tail;/*���е�β*/
	int *array;/*���ݴ洢��*/
}array_queue;

#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue)  ((array_queue->num) == (array_queue->size))

#endif

