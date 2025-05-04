#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct Node {
    int dest;
    int weight;

    Node(int d, int w=1): dest(d), weight(w) {}
};

class Graph{
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

    void dfsHelper(int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for(Node node: adjList[vertex]) {
            if (!visited[node.dest]) { // visit every vertex until they all visited
                dfsHelper(node.dest, visited);
            }
        }
    }

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        dfsHelper(startVertex, visited);
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

    int startNode = 0;

    cout << "DFS Traversal starting from vertex " << startNode << ": ";
    graph.dfs(startNode);
    cout << "\n";

    return 0;
}