// sliding window optimize
#include <iostream>
#include <string>
#include <vector>
#define ULL long long


int modfunc(ULL a, ULL b) {
  return (a%b + b)%b;
}

int main() {
  ULL m;  

  std::string str; 
  std::cin >> m;
  std::cin >> str;
  std::vector<ULL> v;

  // precalculate hash
  int mod = 998244353;
  int hash_val = 31;
  int *power = new int[m]; 
  power[0] = 1;
 
  for (ULL i = 1; i < m; i++) {
    ULL temp = power[i-1] * hash_val;
    int temp_mod = modfunc(temp, mod);
    power[i] = temp_mod;
    // power[i] = modfunc(power[i-1] * hash_val, mod);
  }

  // for(ULL i = 0; i < m; i++) {
  //   power[i] = modfunc(power[i], mod);
  // }

  for(ULL i = 0; i < m; i++) {
    std::cout << power[i] << "\n";
  }

  std::cout << "\n";

  // find hash of first substring
  int h_s = 0;
  for (ULL i = 0; i < m; i++) {
    ULL temp = ((int)str[i] - 96) * power[m - i - 1];
    int temp_mod = modfunc(temp, mod);
    
    ULL tempadd = h_s + temp_mod;
    int tempadd_mod = modfunc(tempadd, mod);

    h_s = tempadd_mod;
  }
  v.push_back(h_s);

  // sliding window
  for (int  i =  m; i < (ULL)str.length(); i++) {
    ULL temp = hash_val * (h_s - power[m - 1] * ((int)str[i - m] - 96)) + (int)(str[i] - 96);
    int temp_mod = modfunc(temp, mod);
    h_s = temp_mod;
    v.push_back(h_s);
  }

  // print results
  for (int i = 0; i < (ULL)v.size(); i++) 
    std::cout << v[i] << "\n";

  delete[] power;

}