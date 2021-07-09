// single source shortest path problem using dijkstras algorithm
#include <iostream>
#include <stdio.h>
#define MAX_INT 2147483647
#define L long long int
// #define L long int


L min_distance(L *dist, bool *spath, L size) {
  L min = MAX_INT; 
  L min_index = 0;
  for (L i = 0; i < size; i++) {
    if(spath[i] == false && dist[i] < min) {
      // printf("min %ld\n", min);
      min = dist[i], min_index = i;
    }
  }
  // printf("min_index %ld", min_index);
  return min_index;
}


void djkstra(L **graph, L size, L source) {
  L *dist = new L[size];
  bool *spath = new bool[size];

  for (L i = 0; i < size; i++) {
    dist[i] = MAX_INT;
    spath[i] = false;
  }

  dist[source] = 0;

  // for all vertices
  for (L i = 0; i < size - 1; i++) {
    L u = min_distance(dist, spath, size);
    spath[u] = true;

    // update neighbors
    // update dist[v] only if not already in shortest path, there is an edge from u to v, 
    // and total weight of path from src to v is smaller than current val of dist[v]
    for (L j = 0; j < size; j++) {
      if (!spath[j] && graph[u][j] && dist[u] != MAX_INT && dist[u] + graph[u][j] < dist[j]) {
        dist[j] = dist[u] + graph[u][j];
      }
    }
  }

  for(L i = 0; i < size; i++) {
    if (dist[i] != MAX_INT) {
      printf("%ld\n", dist[i]);
    }
    else printf("INF\n");
  }

  delete[] dist;
  delete[] spath;
}

int main() {
  L n, m;
  scanf("%ld %ld", &n, &m);

  L **board;
  board = new L*[n];
  for(L i = 0; i < n; i++) 
    board[i] = new L[n];

  
  for(L i = 0; i < n; i++) {
    for(L j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }


  for(L i = 0; i < m; i++){
    L x, y, z;
    scanf("%ld %ld %ld", &x, &y, &z);
    if (board[x - 1][y - 1] == 0) {
        board[x - 1][y - 1] = z;
    } else if (board[x - 1][y - 1] > z) {
        board[x - 1][y - 1] = z;
    }
  }

  djkstra(board, n, 0);

  for(L i = 0; i < n; i++) {
    delete[] board[i];
  }
  delete[] board;

  return 0;
}