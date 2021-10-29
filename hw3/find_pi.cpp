#include <omp.h>
#include <iostream>

using namespace std;

int main()
{

    float pi = 0.0;
    int counter = 0, i = 0;
    const int N = 1000000;
    float x, y;
    unsigned int seed = 42;
#pragma omp parallel shared(counter) firstprivate(i, x, y, seed)
{
    int tid = omp_get_thread_num();
    seed = seed * tid;
#pragma omp for reduction(+: counter)
    for (i = 0; i < N; ++i)
    {   
        x = float(rand_r(&seed)) / RAND_MAX - 0.5;
        y = float(rand_r(&seed)) / RAND_MAX - 0.5;
        if (x * x + y * y <= 0.25)
            counter += 1;
    }
}
    pi = 4 * float(counter) / N;
    cout << pi << endl;
    return 0;

}