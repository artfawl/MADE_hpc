#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

float dotprod(float * a, float * b, size_t N)
{
    int i, tid;
    float sum = 0;

#pragma omp parallel num_threads(4) shared(sum)
#pragma omp for reduction(+:sum)
    for (i = 0; i < N; ++i)
    {
        tid = omp_get_thread_num();
        sum += a[i] * b[i];
        printf("tid = %d i = %d\n", tid, i);
    }

    return sum;
}

float orig_dotprod(float * a, float * b, size_t N)
{
    int i;
    float sum = 0;

    for (i = 0; i < N; ++i)
        sum += a[i] * b[i];

    return sum;
}

int main (int argc, char *argv[])
{
    const size_t N = 100;
    int i;
    float sum;
    float a[N], b[N];


    for (i = 0; i < N; ++i)
    {
        a[i] = b[i] = (double)i;
    }

    sum = 0.0;

//#pragma omp parallel shared(sum)
    sum = dotprod(a, b, N);

    printf("Parallel_Sum = %f\n",sum);

    sum = orig_dotprod(a, b, N);

    printf("Common_Sum = %f\n",sum);

    return 0;
}