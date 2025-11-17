#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

double run_sort(void (*fn)(int*,size_t,Metrics*), int *v, size_t n, Metrics *m) {
    reset_metrics(m);
    clock_t t0 = clock();
    fn(v, n, m);
    clock_t t1 = clock();
    return 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;
}

void copy_array(int *dst, int *src, size_t n) {
    for (size_t i = 0; i < n; i++) dst[i] = src[i];
}

void print_csv(const char *met, size_t n, const char *caso, Metrics m, double t) {
    printf("%s,%zu,%s,%lld,%lld,%.3f\n", met, n, caso, m.cmp, m.swp, t);
}

void fill_random(int *v, size_t n) {
    for (size_t i = 0; i < n; i++) v[i] = rand() % 10000;
}

int main() {
    srand(time(NULL));

    char rgm_str[] = "12345678";
    size_t n_rgm = strlen(rgm_str);
    int rgm[20], temp[20];

    for (size_t i = 0; i < n_rgm; i++)
        rgm[i] = rgm_str[i] - '0';

    Metrics m;
    double t;

    copy_array(temp, rgm, n_rgm);
    t = run_sort(bubble_sort, temp, n_rgm, &m);
    print_csv("bubble", n_rgm, "rgm", m, t);

    copy_array(temp, rgm, n_rgm);
    t = run_sort(selection_sort, temp, n_rgm, &m);
    print_csv("selection", n_rgm, "rgm", m, t);

    copy_array(temp, rgm, n_rgm);
    t = run_sort(insertion_sort, temp, n_rgm, &m);
    print_csv("insertion", n_rgm, "rgm", m, t);

    size_t sizes[] = {100, 1000, 10000};
    size_t q = 3;

    for (size_t s = 0; s < q; s++) {
        size_t n = sizes[s];
        int *base = malloc(n * sizeof(int));
        int *arr = malloc(n * sizeof(int));

        fill_random(base, n);

        copy_array(arr, base, n);
        t = run_sort(bubble_sort, arr, n, &m);
        print_csv("bubble", n, "aleatorio", m, t);

        copy_array(arr, base, n);
        t = run_sort(selection_sort, arr, n, &m);
        print_csv("selection", n, "aleatorio", m, t);

        copy_array(arr, base, n);
        t = run_sort(insertion_sort, arr, n, &m);
        print_csv("insertion", n, "aleatorio", m, t);

        free(base);
        free(arr);
    }

    return 0;
}

