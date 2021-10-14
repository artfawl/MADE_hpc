#pragma once
#include "func.h"
#include<random>

template<class T>
T** mul(T** first, T** second, int n, int m, int k) {
  T** res = new T*[n];
  for(int i=0; i<n; ++i) {
    res[i] = new T[k] {0};
  }
  
  for(int i=0; i<n; ++i)
    for(int l=0; l<k; ++l)
      for(int j=0; j<m; ++j)
        res[i][j] += first[i][j] * second[l][j];
  
  return res;
}

template<class T>
T** random_filling(int n, int m) {
  T** res = new T*[n];
  for(int i=0; i<n; ++i) {
    res[i] = new T[m];
    for(int j=0; j<m; ++j) 
      res[i][j] = std::rand() % 1024;
  }
  return res;
}

template<class T>
void remove_matrix(T** matr, int n, int m) {
  for(int i=0; i<n; ++i)
    delete [] matr[i];
  delete[] matr;
}
