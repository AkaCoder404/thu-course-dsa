// brute force method
#include <iostream>
#include <string>
#include <vector>

#define ULL long long int

int main() {
  ULL m; 
  std::string str;

  std::cin >> m;
  std::cin >> str;

  ULL mod = 998244353;
  std::vector<ULL> v;

  for (int i = 0; i <  (ULL)str.length() - m + 1; i++) {
    std::string temp = str.substr(i, m);
    // std::cout << "word: " << temp << "\n";
    ULL hash_val = 31;
    ULL value = ((int)temp[temp.length() - 1] - 96);
    // std::cout << temp[temp.length() - 1] << " ";
    for (int j = temp.length() - 2; j > -1; j--) {
      value += ((int)temp[j] - 96) * hash_val % mod;
      // std::cout << temp[j] << "*" << hash_val << " ";
      hash_val *= hash_val;
    }
    // std::cout << "\n";
    v.push_back(value);
  }

  // solutions
  for (int i = 0; i < (ULL)v.size(); i++) {
    std::cout << v[i] << "\n";
  }

}