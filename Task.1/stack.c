#include "stack.h"
#include <stdlib.h>
#if memory == LIMITED 
void Push(StackEntry e, Stack* ps)
{
    ps->entry[ps->top++] = e;
}
void CreateStack(Stack* ps)
{
    ps->top = 0;
}
void Pop(StackEntry* e, Stack* ps)
{
    *e = ps->entry[--ps->top];
}
void ClearStack(Stack* ps)
{
    (*ps).top = 0;
}
int StackSize(Stack* ps)
{
    return ((*ps).top);
}
int	StackFull(Stack* ps)
{
    return ((ps->top) >= (MAXSTACK));
}
int StackEmpty(Stack* ps)
{
    return ps->top <= 0;
}
void StackTop(StackEntry* e, Stack* ps)
{
    *e = ps->entry[(ps->top) - 1];
}
void TraverseStack(Stack* ps, void (*pf)(StackEntry))
{
    for (int i = ps->top - 1;i > 0;i--)
    {
        (*pf)(ps->entry[i - 1]);
    }
}
#elif memory == UNLIMITED
void CreateStack(Stack* ps)
{
    ps->top = NULL;
}

void Push(StackEntry e, Stack* ps)
{
    StackNode* p;
    p = (StackNode*)malloc(sizeof(StackNode));
    p->entry = e;
    p->next = ps->top;
    ps->top = p;
    ps->size++;
}

void Pop(StackEntry* pe, Stack* ps)
{
    *pe = ps->top->entry;
    StackNode* p = ps->top;
    ps->top = ps->top->next;
    free(p);
    ps->size--;
}
int StackEmpty(Stack* ps)
{
    if (ps->top)return 1;
}
int StackFull(Stack* ps)
{
    return 0;
}
void StackTop(StackEntry* pe, Stack* ps)
{
    *pe = ps->top->entry;
}
int StackSize(Stack* ps)
{
    return ps->size;
}
void ClearStack(Stack* ps)
{
    StackNode* p = ps->top;
    while (p)
    {
        ps->top = ps->top->next;
        free(p);
        p = ps->top;
    }
}
void TraverseStack(Stack* ps, void (*pf)(StackEntry))
{
    StackNode* p = ps->top;
    while (p)
    {
        (*pf)(p->entry);
        p = ps->top->next;
    }

}
#endif
