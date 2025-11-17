#include "sorts.h"

void reset_metrics(Metrics *m) {
    m->cmp = 0;
    m->swp = 0;
}

void bubble_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            m->cmp++;
            if (v[j] > v[j+1]) {
                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
                m->swp++;
            }
        }
    }
}

void selection_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n; j++) {
            m->cmp++;
            if (v[j] < v[min]) min = j;
        }
        int t = v[i];
        v[i] = v[min];
        v[min] = t;
        m->swp++;
    }
}

void insertion_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 1; i < n; i++) {
        int key = v[i];
        size_t j = i;
        while (j > 0) {
            m->cmp++;
            if (v[j-1] <= key) break;
            v[j] = v[j-1];
            j--;
            m->swp++;
        }
        v[j] = key;
    }
}

