// sliding window optimize bug fix
#include <iostream>
#include <string>
#include <vector>
#define ULL long long int

int mod_func(ULL a, ULL b) {
  // return (a%b + b)%b;
  return a%b;
  // return a%b > 0 ? a%b : (a%b + b)%b;
}

int mult_mod(ULL a, ULL b) {
  ULL prod =   ((a % 998244353) * (b % 998244353)) % 998244353;
  int prod_int = prod % 998244353;
  // std::cout << "prod: " << a << " * " << b << " = " << prod_int << "\n";
  return prod_int;
}

int add_mod(ULL a, ULL b) {
  ULL sum = ((a % 998244353) + (b % 998244353)) % 998244353;
  int sum_int = sum % 998244353;
  return sum_int;
}

int sub_mod(ULL a, ULL b) {
  ULL dif = ((a % 998244353) - (b % 998244353)) % 998244353;
  int dif_int = dif > 0 ? dif : dif + 998244353;
  // std::cout << "prod: " << a << " - " << b << " = " <<  dif_int  << "\n";
  return dif_int;
}


int main() {
  int m;

  std::string str; 
  std::cin >> m;
  std::cin >> str;
  std::vector<int> v;

  int mod = 998244353;
  int hash_val = 31;
  int *power = new int[m]; 
  ULL *power_long = new ULL[m];
  power_long[0] = 1;
  power[0]= 1;

  for(int i = 1; i < m; i++) {
    power_long[i] = mod_func(power_long[i-1] * hash_val, mod);
    power[i] = power_long[i];
  }
  
  // for(ULL i = 0; i < m; i++) {
  //   std::cout << power[i] << "\n";
  // }
  
  // std::cout << "\n";

  // find hash of first substring
  int h_s = 0;
  for(int i = 0; i < m; i++) {
    ULL temp =  mult_mod((int)str[i] - 96, power[m - i - 1]);
    h_s =  add_mod(h_s, temp);
  }
  // v.push_back(h_s);

  printf("%d\n", h_s);

  // brute force
  // for (int i = 0; i < (signed)str.length() - m + 1; i++) {
  //   std::string temp = str.substr(i, m);
  //   long long int val = 0;
  //   for(int j = 0; j < m; j++) {
  //     val = add_mod(val, mult_mod(power[m - j - 1], ((int)temp[j] - 96)));
  //   } 
  //   int ans = val % mod;
  //   printf("%d\n", ans);
  // }



  // // O(1) sliding algorithm
  for (int  i = m; i < (ULL)str.length(); i++) {
    int temp_y = (int)(str[i] - 96);
    int temp_h = h_s;
    int temp_x = (int)(str[i-m] - 96);
    int temp_h_x = mult_mod(power[m-1], temp_x);

    int temp_hv_hx = sub_mod(temp_h, temp_h_x);
    int temp_hv_hx_y = add_mod(mult_mod(temp_hv_hx, hash_val), temp_y);
    h_s = mod_func(temp_hv_hx_y, mod);
    // std::cout << "temp_x: " <<  temp_x <<", temp_y:" << temp_y << ", temp_h:" << temp_h << ", temp_h_x:" << temp_h_x << ", h_s:" << h_s <<"\n"; 
    printf("%d\n", h_s);
    // v.push_back(h_s);
  }


  // // for (int i = 0; i < (ULL)v.size(); i++) 
  // //   std::cout << v[i] << "\n";

  delete[] power;
}
