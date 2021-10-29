#pragma once

template <class T>
void remove_matr(T **matr, int n);

template <class T>
T **mul(T **first, T **second, int n, int m, int k);

template <class T>
T **identity(int n);

template<class T>
void show(T **matr, int n, int m);

template <class T>
T **mat_pow(T **matr, int n, int p);

int **create_graph(int n, float p);

#include "funcs.cpp"