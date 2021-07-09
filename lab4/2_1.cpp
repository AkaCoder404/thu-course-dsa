#include <iostream>
#define INT_MAX 2147483647   
#define M_MAX 10000
using namespace std;

int miniDist(int distance[], int size, bool Tset[]) {
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<size;k++) {
      if(Tset[k]==false && distance[k]<=minimum) {
        minimum=distance[k];
        ind=k;
      }
    }
    return ind;
}

void DijkstraAlgo(int graph[M_MAX][M_MAX], int size, int src) {
    int distance[M_MAX];            
    bool Tset[M_MAX]; 
    
     
    for(int k = 0; k<size; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;             
    
    for(int k = 0; k<size ; k++) {
        int m=miniDist(distance,size, Tset); 
        Tset[m]=true;
        for(int k = 0; k< size; k++) {
          if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
              distance[k]=distance[m]+graph[m][k];
        }
    }
 
    for(int k = 0; k< size; k++) { 
      if (distance[k] != INT_MAX) std::cout << distance[k] << std::endl;
      else std::cout << "INF\n";
    }
}

int main()
{
   
    
    int n, m;
    std::cin >> n >> m;
    int graph[M_MAX][M_MAX];
    
    for (int i = 0; i < m; i++) {
      int x, y, z;
      std::cin >> x >> y >> z;
      graph[x - 1][y - 1] = z;
    }

    DijkstraAlgo(graph,n, 0);
    return 0;                           
}