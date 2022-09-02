#include <stdio.h>
#include "queue.h"
int main()
{
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    printf("%d\n", QueueEmpty(&q));
    printf("enter element\n");
    scanf_s("%d", &e);
    Appened(e, &q);
   Serve(&e, &q);
   printf("%d", e);
 


    return 0;
}