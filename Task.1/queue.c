#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#include "global.h"

#if memory == LIMITED
void CreateQueue(Queue* pq)
{
    pq->size = pq->front = 0;
    pq->rear = -1;
}
void Appened(QueueEntry e, Queue* pq)
{
    pq->rear = (pq->rear + 1) % maxQueue;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Serve(QueueEntry* pe, Queue* pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % maxQueue;
    pq->size--;
}
int QueueEmpty(Queue* pq)
{
    return !(pq->size);
}
int QueueFull(Queue* pq)
{
    return(pq->size == maxQueue);
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
void ClearQueue(Queue* pq)
{
    CreateQueue(pq);
}
void TraverseQueue(Queue* pq, void (*pf)(QueueEntry))
{
    for (int pos = pq->front, s = 0;s < pq->size;s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % maxQueue;
    }
}
#elif memory == UNLIMITED
void CreateQueue(Queue* pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->Size = 0;
}
void Appened(QueueEntry e, Queue* pq)
{
    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
    p->next = NULL;
    p->entry = e;
    if (!pq->rear)
    {
        pq->front = p;
    }
    else
    {
        pq->rear->next = p;
    }
    pq->rear = p;
    pq->Size++;
}
void Serve(QueueEntry* pe, Queue* pq)
{
    QueueNode* p = pq->front;
    *pe = pq->front->entry;
    pq->front = pq->front->next;
    free(p);
    if (!pq->front)
    {
        pq->rear = NULL;
    }
    pq->Size--;
}
int QueueEmpty(Queue* pq)
{
    return !pq->Size;
}
int QueueFull(Queue* pq)
{
    return 0;
}
int QueueSize(Queue* pq)
{
    return pq->Size;
}
void ClearQueue(Queue* pq)
{
    while (pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->Size = 0;
}
void TraverseQueue(Queue* pq, void(*pf)(QueueEntry))
{
    for (QueueNode* pn = pq->front;pn;pn = pn->next)
    {
        (*pf)(pn->entry);
    }
}
#endif 
