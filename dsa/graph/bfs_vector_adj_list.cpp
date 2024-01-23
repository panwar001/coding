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
        
        void BFS(int v);
        
        void print();
    
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjList.resize(numVertices);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Graph::BFS(int v) {
    
    deque<int> queue;
    queue.push_back(v);
    int current_vertex;

    // while queue is not empty
    while(!queue.empty()) {

        // pop the queue
        current_vertex = queue.front();
        visited[current_vertex] = true;
        cout<< current_vertex << " ";
       
        // pop queue and add its edge nodes to queue
        queue.pop_front();
        for (int j = 0; j < adjList[current_vertex].size(); j++) { {
            if(!visited[adjList[current_vertex][j]]) {
                queue.push_back(adjList[current_vertex][j]);
            }
        }
    }
  }
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

    cout << endl << "BFS to Graph G" << endl; 
    g.BFS(0);
    
    return 0;
}
