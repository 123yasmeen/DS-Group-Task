#ifndef QUEUE 
#define QUEUE
#include "global.h"
void CreateQueue(Queue*);
void Appened(QueueEntry, Queue*);
void Serve(QueueEntry*, Queue*);
int QueueEmpty(Queue*);
int QueueFull(Queue*);
int QueueSize(Queue*);
void ClearQueue(Queue*);
void TraverseQueue(Queue*, void (*) (QueueEntry));
#endif
