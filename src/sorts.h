#ifndef SORTS_H
#define SORTS_H
#include <stddef.h>

typedef struct {
    long long cmp;
    long long swp;
} Metrics;

void reset_metrics(Metrics *m);
void bubble_sort(int *v, size_t n, Metrics *m);
void selection_sort(int *v, size_t n, Metrics *m);
void insertion_sort(int *v, size_t n, Metrics *m);

#endif

