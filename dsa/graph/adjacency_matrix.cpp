//Ref - https://iq.opengenus.org/adjacency-list-and-matrix-in-cpp/
#include <bits/stdc++.h>

using namespace std;

class Graph{
    //data member
    public: 
        int numVertices;
        vector<vector<int>> adjMatrix;
        
        // Constructor
        Graph(int numVertices);
       
        //member function
        void addEdge(int src, int dest);
        void deleteEdge(int src, int dest);
        bool isConnected(int src, int dest);
        void print();
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    
    // Initialize adjacency matrix to all zeros
    for (int i = 0; i < numVertices; i++) {
        vector<int> row(numVertices, 0);
        adjMatrix.push_back(row);
    }
}

// Add edge between two vertices with unit weight
void Graph::addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
}

// Delete edge between two vertices
void Graph::deleteEdge(int src, int dest) {
    adjMatrix[src][dest] = 0;
}

// Check if two vertices are directly connected
bool Graph::isConnected(int src, int dest) {
    return (adjMatrix[src][dest] == 1);
}

// Print out adjacency matrix
void Graph::print() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
   Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();  // 0 1 1 0 0 
                // 0 0 0 1 0 
                // 0 0 0 1 0 
                // 0 0 0 0 1 
                // 0 0 0 0 0
    cout << endl;
    g.deleteEdge(2, 3);
    cout << "Deleting edge (2,3)" << endl;
    g.print();  // 0 1 1 0 0 
                // 0 0 0 1 0 
                // 0 0 0 0 0 
                // 0 0 0 0 1 
                // 0 0 0 0 0
    cout << endl << "Check edge connected " << endl;
    cout << g.isConnected(0, 2) << endl;  // true
    cout << g.isConnected(0, 3) << endl;  // false

    return 0;
}
