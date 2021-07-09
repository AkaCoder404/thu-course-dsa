// floyd warshall method

#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 1000000
#define MIN(a, b) (a) < (b) ? (a) : (b)

void floyd_warshall_algo(int **graph, int size) {
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }


  for(int i = 0; i < size; i++) {
    if (graph[0][i] == MAX) std::cout << "INF\n";
    else std::cout << graph[0][i] <<"\n";
  }


}

int main() {
  int n, m; 
  std::cin >> n >> m;

  int **graph; 
  graph = new int*[n];
  for(int i = 0; i < n; i++) {
    int *rows = new int[n]; 
    std::fill_n(rows, n, MAX);
    
    graph[i] = rows;
  }
  // memset(graph, MAX, sizeof(graph));

  graph[0][0] = 0;
  
  for (int i = 0; i < m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    graph[x - 1][y - 1] = z;
  }

  floyd_warshall_algo(graph, n);


  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) 
  //     std::cout << graph[i][j] << " ";
  //   std::cout << "\n";
  // }
    

  
  // delete graph 
  for (int i = 0; i < n; i++) {
    delete[] graph[i];
  }

  delete[] graph;
  
  return 0;


}