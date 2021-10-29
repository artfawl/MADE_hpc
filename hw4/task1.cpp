#include "funcs.h"
#include <iostream>

using namespace std;

void show_adj_m(int **adj, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

int num_of_paths(int first_vert, int sec_vert, int length, int **adj, int n_nodes)
{
    if (first_vert == sec_vert)
        return 0;
    int **powed_adj = mat_pow(adj, n_nodes, length);
    //show_adj_m(powed_adj, n_nodes);
    int res = powed_adj[first_vert][sec_vert];
    remove_matr(powed_adj, n_nodes);
    return res;
}

int main()
{
    int n = 5;
    float p = 0.3;
    int **adj = create_graph(n, p);
    int vert1 = 1, vert2 = 4;
    adj[vert1][vert2] = adj[vert2][vert1] = 1;
    show_adj_m(adj, n);
    int length_of_path = 3;
    int paths = num_of_paths(vert1, vert2, length_of_path, adj, n);
    cout << "Колличество маршрутов длины " << length_of_path << " равно " << paths << endl;
    remove_matr(adj, n);
    //show_adj_m(mat_pow(adj, n, 2), n);
    return 0;
}