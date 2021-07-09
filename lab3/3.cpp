// brute force method
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> results;
  std::vector<std::priority_queue<int>> v;
  for (int i = 0; i < n; i++) {
    std::priority_queue<int> pq;
    int temp;
    scanf("%d", &temp);
    pq.push(temp);
    v.push_back(pq);
  }

  for (int i = 0; i < m; i++) {
    int first, second;
    // std::cin >> first >> second;
    scanf("%d %d", &first, &second);

    int first_big = v[first - 1].top();
    v[second - 1].push(first_big);
    v[first - 1].pop();
    // results.push_back(first_big);
    // std::cout << first_big << "\n";
    printf("%d\n", first_big);

  }

  // for (int i = 0; i < (signed)results.size(); i++) {
  //   std::cout << results[i] << "\n";
  // }

}