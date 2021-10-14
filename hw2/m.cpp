#include "func.h"
#include<iostream>
#include<chrono>

using namespace std;


int main() {
  int sizes[6] = {500, 512, 1000, 1024, 2000, 2048};

  for(int i=0; i<6; ++i) {
  int** a = random_filling<int>(sizes[i], sizes[i]);
  int** b = random_filling<int>(sizes[i], sizes[i]);

  auto begin = std::chrono::high_resolution_clock::now();
  int** c = mul(a, b, sizes[i], sizes[i], sizes[i]);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  cout << "Time with size " << sizes[i] << " is " << elapsed.count() * 1e-9 << " s" << endl;

  remove_matrix(a, sizes[i], sizes[i]);
  remove_matrix(b, sizes[i], sizes[i]);
  remove_matrix(c, sizes[i], sizes[i]);
  }



return 0;
}