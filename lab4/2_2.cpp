#include <iostream>
#define INT_MAX 2147483647
using namespace std;

#define MAXV 1000000

class EdgeNode{
    public:
        int key;
        int weight;
        EdgeNode *next;
        EdgeNode(int, int);
};

EdgeNode::EdgeNode(int key, int weight){
    this->key = key;
    this->weight = weight;
    this->next = NULL;
}

class Graph{
    bool directed;
    int size;
    public:
        EdgeNode *edges[MAXV + 1];
        Graph(bool, int);
        ~Graph();
        void insert_edge(int, int, int, bool, int);
};

Graph::Graph(bool directed, int size){
    this->directed = directed;
    this->size = size;
    for(int i = 1; i < (size+ 1); i ++){
        this->edges[i] = NULL;
    }
}

Graph::~Graph(){ }

void Graph::insert_edge(int x, int y, int weight, bool directed, int size){
    if(x > 0 && x < (size + 1) && y > 0 && y < (size + 1)){
        EdgeNode *edge = new EdgeNode(y, weight);
        edge->next = this->edges[x];
        this->edges[x] = edge;
        if(!directed){
            insert_edge(y, x, weight, true, size);
        }
    }
}

void init_vars(bool *discovered, int *distance, int *parent, int size ){
    for(int i = 1; i < size + 1; i ++){
        discovered[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
}

void dijkstra_shortest_path(Graph *g, int *parent, int *distance, int start, int size){

    bool *discovered = new bool[size + 1];
    EdgeNode *curr;
    int v_curr;
    int v_neighbor;
    int weight;
    int smallest_dist;

    init_vars(discovered, distance, parent, size);

    distance[start] = 0;
    v_curr = start;

    while(discovered[v_curr] == false){

        discovered[v_curr] = true;
        curr = g->edges[v_curr];

        while(curr != NULL){

            v_neighbor = curr->key;
            weight = curr->weight;

            if((distance[v_curr] + weight) < distance[v_neighbor]){
                distance[v_neighbor] = distance[v_curr] + weight;
                parent[v_neighbor] = v_curr;
            }
            curr = curr->next;
        }

        //set the next current vertex to the vertex with the smallest distance
        smallest_dist = INT_MAX;
        for(int i = 1; i < size + 1; i++){
            if(!discovered[i] && (distance[i] < smallest_dist)){
                v_curr = i;
                smallest_dist = distance[i];
            }
        }
    }

    delete[] discovered;
}

void print_distances(int *distance, int size){
    for(int i = 1; i < size + 1; i++){
        if(distance[i] != INT_MAX){
            cout << distance[i] << endl;
        }
        else cout << "INF\n";
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    Graph *g = new Graph(false, n);

    int *parent = new int[n];
    int *distance = new int[n];
    int start = 1;

    for(int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      g->insert_edge(x, y, z, false, n);
    }

    dijkstra_shortest_path(g, parent, distance, start, n);
    print_distances(distance, n);

    delete g;
    delete[] parent;
    delete[] distance;
    return 0;
}