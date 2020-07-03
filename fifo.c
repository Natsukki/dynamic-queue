#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(struct fifo));
    if (!fifo)
        return NULL;
    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
    return fifo;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *f_elt = malloc(sizeof(struct list));
    if (!f_elt)
        return;
    f_elt->next = NULL;
    f_elt->data = elt;
    if (fifo->tail)
        fifo->tail->next = f_elt;
    if (!fifo->head)
        fifo->head = f_elt;
    fifo->tail = f_elt;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo->head)
        return;
    if (fifo->size == 1)
        fifo->tail = NULL;
    struct list *tmp = fifo->head;
    fifo->size -= 1;
    fifo->head = fifo->head->next;
    free(tmp);
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size != 0)
        fifo_pop(fifo);
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *tmp = fifo->head;
    while (tmp)
    {
        printf("%d", tmp->data);
        if (tmp->next)
            printf("-");
        tmp = tmp->next;
    }
    printf("\n");
}
