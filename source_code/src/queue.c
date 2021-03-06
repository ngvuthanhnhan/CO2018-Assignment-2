#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size == MAX_QUEUE_SIZE) 
        return;
	if ((empty(q)) || (q->proc[q->size-1]->priority < proc->priority)) {
		q->proc[q->size++] = proc;
		return;
	}
    for (int i = 0; i < q->size; i++) {
        if (proc->priority <= q->proc[i]->priority) {
            q->size++;
            for (int k = q->size - 1; k > i; k--) {
                q->proc[k] = q->proc[k - 1]; 
            }
            q->proc[i] = proc;
            break;
        }
    }
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (!empty(q)) {
		q->size--;
		struct pcb_t * temp = q->proc[q->size];
		q->proc[q->size] = NULL;
		return temp;
	}
	return NULL;
}

