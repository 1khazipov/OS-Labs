#include <stdio.h>
#include <stdlib.h>


void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    int *r = malloc(sizeof(int));
    *r = *x + *y;
    return r;
}

void *addDouble(const void *a, const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;
    double *r = malloc(sizeof(double));
    *r = *x + *y;
    return r;
}

void *mulInt(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    int *r = malloc(sizeof(int));
    *r = *x * *y;
    return r;
}

void *mulDouble(const void *a, const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;
    double *r = malloc(sizeof(double));
    *r = *x * *y;
    return r;
}

void *meanInt(const void *a, const void *b) {
    int* x = (int*) a;
    int *y = (int*) b;
    int* r = malloc(sizeof(int));
    *r = *x + *y;
    return r;
}

void *meanDouble(const void *a, const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;
    double *r = malloc(sizeof(double));
    *r = *x + *y;
    return r;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *)) {

    void *output;

    if (size == sizeof(int)) { // base is a pointer to an integer

        int *arr = (int*) base;
        int result = *(int*)initial_value;
        for (int i = 0; i < n; i++) {
            int *returned = opr(&result, arr + i);
            result = *returned;
            free(returned);
        }
        if (opr == meanInt) {
            result /= n;
        }
        int* int_output = malloc(sizeof(int));
        *int_output = result;
        output = int_output;

    } else { // base is a pointer to a double

        double *arr = (double*) base;
        double result = *(double*)initial_value;
        for (int i = 0; i < n; i++) {
            double *returned = opr(&result, arr + i);
            result = *returned;
            free(returned);
        }
        if (opr == meanDouble) {
            result /= n;
        }
        double* double_output = malloc(sizeof(double));
        *double_output = result;
        output = double_output;

    }

    return output;
}


int main() {

    int *ints = malloc(sizeof(int) * 5);
    double *doubles = malloc(sizeof(double) * 5);

    for (int i = 0; i < 5; i++) {
        ints[i] = i * 2 + 1;
        doubles[i] = (double) (i * 2 + 1) / 10.0;
    }

    int initial_i;
    double initial_d;

    // Addition

    int *result1a;

    initial_i = 0;
    result1a = aggregate(ints, sizeof(int), 5, &initial_i, addInt);

    printf("%d\n", *result1a);

    double *result2a;

    initial_d = 0.0;
    result2a = aggregate(doubles, sizeof(double), 5, &initial_d, addDouble);

    printf("%f\n", *result2a);


    // Multiplication

    int *result1m;

    initial_i = 1;
    result1m = aggregate(ints, sizeof(int), 5, &initial_i, mulInt);

    printf("%d\n", *result1m);

    double *result2m;

    initial_d = 1.0;
    result2m = aggregate(doubles, sizeof(double), 5, &initial_d, mulDouble);

    printf("%f\n", *result2m);



    // Mean

    int *result1mean;

    initial_i = 0;
    result1mean = aggregate(ints, sizeof(int), 5, &initial_i, meanInt);

    printf("%d\n", *result1mean);

    double *result2mean;

    initial_d = 0.0;
    result2mean = aggregate(doubles, sizeof(double), 5, &initial_d, meanDouble);

    printf("%f\n", *result2mean);


    // free the pointers
    free(ints);
    free(doubles);
    free(result1a);
    free(result1m);
    free(result1mean);
    free(result2a);
    free(result2m);
    free(result2mean);

    return EXIT_SUCCESS;
}

