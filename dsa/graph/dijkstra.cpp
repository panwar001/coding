#include <bits/stdc++.h>
using namespace std;

class Graph{
    //data member
    public: 
        map<int, list<pair<int, int>>> adjacencyList;
        
        //member function
        void addEdge(int u, int v, int w);
        
        void DijkstraPath(int u);
};

void Graph::addEdge(int u, int v, int w) {
    // undirected graph with weight
    adjacencyList[u].push_back(make_pair(v, w));
    adjacencyList[v].push_back(make_pair(u, w));
}

void Graph::DijkstraPath(int u) {

    //method for making min-heap using default priority_queue
    // default priority queue returns max heap, so add comparator function to convert to min heap
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater <pair<int, int>> > pq;

    int V = adjacencyList.size(); // to count the number of vertices
    
    // Create a vector of size n and initialises each element to INT_MAX
    vector<int> dist(V, INT_MAX); // All distance from source are infinite 
    
    pq.push(make_pair(u, 0));
    dist[u] = 0;

    // while queue is not empty
    while(!pq.empty()) {
        // While queue is not empty  
        // Extract the first minimum distance from the priority queue  
        // vertex label is stored in second of pair (it  
        // has to be done this way to keep the vertices  
        // sorted distance  
        // pop the queue

        int u = pq.top().first;
        pq.pop();

        for (auto itr = adjacencyList[u].begin(); itr != adjacencyList[u].end(); ++itr) {
            int vertex = (*itr).first;
            int weight = (*itr).second;
            
            if(dist[vertex] > dist[u]+weight) {
                dist[vertex] = dist[u]+weight;
                pq.push(make_pair(vertex, dist[vertex]));
            }
        }
    }

    printf("Vertex \tDistance from Source\n"); // Print the result  
    for (int i = 0; i < V; ++i)  {
         printf("%d \t\t %d\n", i, dist[i]); // The shortest distance from source 
    }
}

int main() {
    cout << "Dijktra's Algorithm!" << endl;
    Graph g;
    g.addEdge(0, 1, 4); // add root node with neighour vertex and weight  
    g.addEdge(0, 7, 8);  
    g.addEdge(1, 2, 8);  
    g.addEdge(1, 7, 11);  
    g.addEdge(2, 3, 7);  
    g.addEdge(2, 8, 2);  
    g.addEdge(2, 5, 4);  
    g.addEdge(3, 4, 9);  
    g.addEdge(3, 5, 14);  
    g.addEdge(4, 5, 10);  
    g.addEdge(5, 6, 2);  
    g.addEdge(6, 7, 1);  
    g.addEdge(6, 8, 6);  
    g.addEdge(7, 8, 7);  

    cout << "shortest path from vertex 0 to vertex 8" << endl; 
    g.DijkstraPath(0);
    
    return 0;
}
