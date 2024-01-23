// Ref - //Ref - https://iq.opengenus.org/adjacency-list-and-matrix-in-cpp/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    //data member
    public: 
        int numVertices;
        vector<vector<int>> adjList;
        map<int, int> visited;
        
         // Constructor
        Graph(int numVertices);
        
        //member function
        void addEdge(int v, int w);
        void print();
    
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjList.resize(numVertices);
}

// visualization of vector<vector<int>>
/*
vector<vector<int>> adj;
adj = { { 1, 2, 3 }, 
      { 4, 5, 6 }, 
      { 7, 8, 9, 4 } }; 
adj[0] returns { 1, 2, 3 }
*/

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Graph::print() {
    for (int i = 0; i < numVertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    std::cout << "Adjacency List!" << std::endl;
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();
    // Output:
    // 0: 1 4 
    // 1: 0 2 3 4 
    // 2: 1 3 
    // 3: 1 2 4 
    // 4: 0 1 3 

    
    return 0;
}
