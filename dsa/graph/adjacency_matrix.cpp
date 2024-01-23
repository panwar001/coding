#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void deleteEdge(int src, int dest) {
        // Find the index of the destination vertex in the source vertex's adjacency list
        int destIndex = -1;
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                destIndex = i;
                break;
            }
        }
        // Remove the destination vertex from the source vertex's adjacency list
        if (destIndex != -1) {
            adjList[src].erase(adjList[src].begin() + destIndex);
        }

        // Find the index of the source vertex in the destination vertex's adjacency list
        int srcIndex = -1;
        for (int i = 0; i < adjList[dest].size(); i++) {
            if (adjList[dest][i] == src) {
                srcIndex = i;
                break;
            }
        }
        // Remove the source vertex from the destination vertex's adjacency list
        if (srcIndex != -1) {
            adjList[dest].erase(adjList[dest].begin() + srcIndex);
        }
    }

    bool isConnected(int src, int dest) {
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
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

    g.deleteEdge(1, 4);

    g.print();
    // Output:
    // 0: 1 4 
    // 1: 0 2 3 
    // 2: 1 3 
    // 3: 1 2 4 
    // 4: 0 3 

    cout << g.isConnected(0, 1) << endl; // Output: true
    cout << g.isConnected(0, 2) << endl; // Output: false
 
    return 0;

}
