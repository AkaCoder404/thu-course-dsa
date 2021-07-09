
#include <limits.h>
#include <stdio.h>
  
// Number of vertices in the graph
#define V 5
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
long int minDistance(long int dist[], bool sptSet[])
{
    long int min = INT_MAX, min_index;
  
    for (long int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

 

void dijkstra(long int graph[V][V], long int src)
{
    long int dist[V]; 
  
    bool sptSet[V]; 
    for (long int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  

    dist[src] = 0;
  
    for (long int count = 0; count < V - 1; count++) {

        long int u = minDistance(dist, sptSet);
  
        sptSet[u] = true;

        for (long int v = 0; v < V; v++)
          if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
            && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
    }


    for(long int i = 0; i < V; i++) {
      printf("%ld ", dist[i]);
    }
  
}
  
int main()
{ 

  long int n, m;
  scanf("%ld %ld", &n, &m);

  long int graph[V][V]; 

  for(long int i = 0; i < m; i++){
    long int x, y, z;
    scanf("%ld %ld %ld", &x, &y, &z);
    graph[x - 1][y - 1] = z;
    
  }
    
  dijkstra(graph, 0);
  
    return 0;
}