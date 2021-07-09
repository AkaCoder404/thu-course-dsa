// revers pairs brute force method
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int *numbers = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> numbers[i];
  }


  int count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) { 
      if (numbers[i] > numbers[j]) count++;
    }
  }

  std::cout << count;


  delete [] numbers;



}