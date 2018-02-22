#include <bits/stdc++.h>

using namespace std;


struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode *head;
};

 
class Graph {

    int size;
    struct AdjList* array;
    int** adjMatrix;

    AdjListNode* newAdjListNode(int dest) {
        AdjListNode* newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = NULL;
        return newNode;
    }

public:

    Graph(int s) {
        size = s;
        array = new AdjList[size];
        adjMatrix = new int*[size];
        for (int i = 0 ; i < size ; ++i) {
            array[i].head = NULL;
            adjMatrix[i] = new int[size];
            for (int j = 0 ; j < size ; ++j)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int src, int dest) {
        // Check the case when the node has not been created yet
        if (dest >= size) {
            cout << "Node " << dest << " is not present in the graph!!" << endl;
            return;
        }

        // Update the adjacency list
        AdjListNode* newNode = newAdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
        newNode = newAdjListNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;

        // Update the adjacency matrix
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void printGraph() {
        for (int i = 0; i < size; ++i) {
            AdjListNode* curNode = array[i].head;
            cout << "Vertex " << i;
            while (curNode) {
                cout << " -> " << curNode->dest;
                curNode = curNode->next;
            }
            cout << endl;
        }
    }

    void printAdjacencyMatrix() {
        for (int i = 0 ; i < size ; ++i) {
            for (int j = 0 ; j < size ; ++j)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {

    int size, num = 0;
    cout << "Enter the number of edges: ";
    cin >> size;
    Graph graph(size);

    for (int i = 0 ; i < size ; ++i) {
        cout << "Enter the adjacent vertices to vertex " << i << ": (-1 to stop) ";
        while (1) {
            cin >> num;
            if (num == -1)
                break;
            graph.addEdge(i, num);
        }
    }

    cout << "\nAdjacency List:" << endl;
    graph.printGraph();
    cout << "\nAdjacency Matrix:" << endl;
    graph.printAdjacencyMatrix();

    return 0;
}