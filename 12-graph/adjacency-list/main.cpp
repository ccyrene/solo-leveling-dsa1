#include<iostream>
#include<list>
#include<vector>

using namespace std;

// Node for the adjacency list
struct Node {
    int dest;
    int weight; // For weighted graphs

    Node(int d, int w=1): dest(d), weight(w) {}
};

class Graph {
public:
    int numVertices;
    vector<list<Node>> adjList;
    bool directed = false;

    Graph(int V): numVertices(V), adjList(V) {}

    void addEdge(int src, int dest, int weight=1) {
        adjList[src].push_back(Node(dest, weight));
        if (!directed)
            adjList[dest].push_back(Node(src, weight));
    }

    void visualize() {
        for(int i=0; i<numVertices; i++){
            cout << "Vertex "<< i << ": ";
            for(Node node: adjList[i])
                cout << node.dest << "(" << node.weight << ") ";
            cout << "\n";
        }
    }

};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency List Representation: Vertic(weight)\n";
    graph.visualize();

    return 0;
}