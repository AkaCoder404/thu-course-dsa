// reverse pairs using split/merge technique
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define ULL unsigned long long
#define LL long long
#define L long

ULL conquer_and_count(std::vector<ULL> &v, ULL left_index, ULL mid_index, ULL right_index) {
  std::vector<ULL> temp_left;
  std::copy(v.begin() + left_index, v.begin() + mid_index + 1, std::back_inserter(temp_left));

  std::vector<ULL> temp_right;
  std::copy(v.begin() + mid_index + 1, v.begin() +  right_index + 1, std::back_inserter(temp_right)); 

  // std::cout << "\nconquer left: ";
  // for(size_t i = 0; i < temp_left.size(); i++) std::cout << temp_left[i] << " ";  
  // std::cout << "\nconquer right: ";
  // for(size_t i = 0; i < temp_right.size(); i++) std::cout << temp_right[i] << " ";
  // std::cout << "\n";

  size_t i = 0, j = 0, k = left_index, inversions = 0;

  // find reversed pairs
  while (i < temp_left.size() && j < temp_right.size()) {
    if (temp_left[i] <= temp_right[j])
      v[k++] = temp_left[i++];
    else {
      v[k++] = temp_right[j++];
      //count the inversions
      ULL count = (mid_index +1)-(left_index+i);
      inversions +=count;
    }
  }

  while (i < temp_left.size()) v[k++] = temp_left[i++];
  while (j < temp_right.size()) v[k++] = temp_right[j++];

  // std::cout << "inversions: " << inversions << " \n";
  return inversions;
}

ULL divide(std::vector<ULL> &v, ULL low, ULL high) {
  if (low >= high) return 0;
  ULL mid = low + (high-low) / 2;
  ULL left_inversions = divide(v, low, mid);
  ULL right_inversions = divide(v, mid+1, high);
  ULL mergeInversions = conquer_and_count(v, low, mid, high);
  return left_inversions + right_inversions + mergeInversions;
}


int main() {
  ULL n;
  std::cin >> n;
  std::vector<ULL> v;

  for (ULL i = 0; i < n; i++) {
    ULL temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  std::cout << divide(v, 0, n - 1) << "\n";

}