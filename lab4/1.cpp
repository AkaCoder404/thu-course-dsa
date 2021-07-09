// kruskals algorithm using union find algorithm to check for cycles
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> node_pairs;

struct Graph {
  int verticle, edge;
  std::vector<std::pair <int, node_pairs> > edges; 
  
  Graph(int verticle, int edge) {
    this->verticle = verticle;
    this->edge = edge;
  }

  void addEdge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
  }
};

// union find algorithm to check for cycles
struct DisjointSets {
  int *parent, *rnk;
  int n;

  DisjointSets(int n) {
    this->n = n;
    parent = new int[n+1];
    rnk = new int[n+1];

    for (int i = 0; i <= n; i++) {
      rnk[i] = 0;
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
  }

  void merge(int x, int y){
    x = find(x), y = find(y);
    
    if (rnk[x] > rnk[y]) parent[y] = x;
    else parent[x] = y;

    if (rnk[x] == rnk[y]) rnk[y]++;
  }
};

int kruskalMST(Graph &g, int V) {
    // weight sum
    int mst_wt = 0; 
  
    // sort edges in increasing order on basis of cost
    std::sort(g.edges.begin(), g.edges.end());
  
    // create disjoint sets
    DisjointSets ds(V);
  
    // iterate through all sorted edges
    std::vector< std::pair<int, node_pairs> >::iterator it;
    for (it = g.edges.begin(); it != g.edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // check if the selected edge is creating a cycle or not (cycle is created if u and v belong to same set)
        if (set_u != set_v) {
            // current edge will be in the MST
            // cout << u << " - " << v << endl;
            
            // update MST weight
            mst_wt += it->first;
  
            // merge two sets
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
}

int main() {
  int n, m; //nodes and edges
  std::cin >> n >> m;
  
  // build graph
  Graph g(n, m);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    std:: cin >> x >> y >> z;
    g.addEdge(x, y, z);
  }
  
  // kruskal mst algorithm
  int mst_wt = kruskalMST(g, n);
  std::cout << mst_wt;
}