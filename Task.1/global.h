#ifndef GLOBAL_H
#define GLOBAL_H
#define memory UNLIMITED
#define LIMITED 1 
#define UNLIMITED 2 
typedef int QueueEntry;
typedef int StackEntry;
#if memory == LIMITED
#define MAXSTACK 100
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;


#define maxQueue 10
typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[maxQueue];
}Queue;


#elif memory == UNLIMITED
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode* next;
}QueueNode;
typedef struct queue
{
    QueueNode* front;
    QueueNode* rear;
    int Size;
}Queue;

typedef struct StackNode
{
    StackEntry entry;
    struct StackNode* next;
}StackNode;
typedef struct Stack
{
    StackNode* top;
    int size;
}Stack;
#endif




#endif 
