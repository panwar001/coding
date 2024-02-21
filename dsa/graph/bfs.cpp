#include <bits/stdc++.h>
using namespace std;

class Graph{
    //data member
    public: 
        map<int, list<int>> adjacencyList;
        map<int, int> visited;
        
        //member function
        void addEdge(int v, int w);
        
        void BFS(int v);
};

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
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
        for (auto itr = adjacencyList[current_vertex].begin(); itr != adjacencyList[current_vertex].end(); ++itr) {
            if(!visited[*itr]) {
                queue.push_back(*itr);
            }
        }
    }
}

int main() {
    std::cout << "Hello world!" << std::endl;

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);

    cout << "BFS to Graph G" << endl; 
    g.BFS(2);
    
    return 0;
}
