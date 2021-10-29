#include "funcs.h"
#include <omp.h>
#include <iostream>

using namespace std;

double **transition_matrix(int **adj, int n)
{
    double **res = new double *[n];
    for (int i = 0; i < n; ++i)
        res[i] = new double[n]{0};

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = 0; j < n; ++j)
            sum += adj[i][j];
        for (int j = 0; j < n; ++j)

            res[j][i] = double(adj[i][j]) / sum;
    }
    return res;
}

//without random teleportation to use fast function for multiplication matrices
double **simple_page_rank(int **adj, int n_nodes, int iters)
{
    double** P = transition_matrix(adj, n_nodes);
    //show(P, n_nodes, n_nodes);
    double** first = new double*[n_nodes];
    for(int i=0; i<n_nodes; ++i)
        first[i] = new double[2] {1./n_nodes};
    double** temp = mat_pow(P, n_nodes, iters);
    double** res = mul(temp, first, n_nodes, n_nodes, 1);
    remove_matr(P, n_nodes);
    remove_matr(temp, n_nodes);
    remove_matr(first, n_nodes);
    return res;
}

int main() {
    int n = 5;
    float p = 0.4;
    int **adj = create_graph(n, p);
    show(adj, n, n);
    double** page_rank = simple_page_rank(adj, n, 25);
    cout << "page rank vector: " << endl;
    show(page_rank, n, 1);

    remove_matr(adj ,n);
    remove_matr(page_rank, n);

    return 0;
}