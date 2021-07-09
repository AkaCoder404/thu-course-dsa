// comparing apples with apples
#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#define MIN(a, b) (a) < (b) ? (a) : (b)


void sum_rows1(double* a, double* b, long n) {
long i, j;
for (i = 0; i < n; i++) { b[i] = 0;
for (j = 0; j < n; j++) b[i] += a[i * n + j];
} }

int main() {

  double A[9] = { 0, 1, 2, 4, 8, 16, 32, 64, 128};
double *B = A + 3;
sum_rows1(A, B, 3); 


  for(int i = 0; i < 3; i++) std::cout << B[i] << " ";

  for(int i = 0; i < 3; i++) 
    for(int j = 0; j < 3; j++) 
      std::cout  << A[i * 3 + j] << " ";

  
}