#pragma once
#include "funcs.h"
#include <omp.h>
#include <iostream>

using namespace std;

template <class T>
void show(T **matr, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << matr[i][j] << " ";
        cout << endl;
    }
}

template <class T>
void remove_matr(T **matr, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matr[i];
    delete[] matr;
}

template <class T>
T **mul(T **first, T **second, int n, int m, int k)
{
    T **res = new T *[n];
    for (int i = 0; i < n; ++i)
    {
        res[i] = new T[k]{0};
    }

    for (int i = 0; i < n; ++i)
        for (int l = 0; l < m; ++l)
            for (int j = 0; j < k; ++j)
                //for (int l = 0; l < m; ++l)
                res[i][j] += first[i][l] * second[l][j];

    return res;
}

template <class T>
T **identity(int n)
{
    T **res = new T *[n];
    for (int i = 0; i < n; ++i)
    {
        res[i] = new T[n]{0};
        res[i][i] = 1;
    }
    return res;
}

template <class T>
T **mat_pow(T **matr, int n, int p)
{
    if (p == 0)
        return identity<T>(n);
    T **res;
    T **tmp;
    if (p % 2 == 0)
    {
        T **tmp = mat_pow(matr, n, p / 2);
        res = mul(tmp, tmp, n, n, n);
        remove_matr(tmp, n);
        return res;
    }
    tmp = mat_pow(matr, n, p - 1);
    res = mul(tmp, matr, n, n, n);
    remove_matr(tmp, n);
    return res;
}

// generation of random graph
int **create_graph(int n, float p)
{
    int **adj_matr = new int *[n];
    bool flag = false;
    for (int i = 0; i < n; ++i)
        adj_matr[i] = new int[n]{0};

    for (int i = 0; i < n; ++i)
    {
        flag = false;
        for (int j = i + 1; j < n; ++j)
        {
            if (float(rand()) / RAND_MAX < p)
            {
                adj_matr[i][j] = adj_matr[j][i] = 1;
                flag = true;
            }
        }
        if (!flag) // to make graph connected
        {
            int temp = rand() % n;
            adj_matr[i][temp] = adj_matr[temp][i] = 1;
        }
    }
    return adj_matr;
}