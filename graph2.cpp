#include <bits/stdc++.h>
#include "queue.h"
#include "stack.h"

using namespace std;


struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode *head;
};

 
class Graph {

    int nodes, edges;
    struct AdjList* array;
    int** adjMatrix;

    AdjListNode* newAdjListNode(int dest) {
        AdjListNode* newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = NULL;
        return newNode;
    }  

    void addEdge(int src, int dest) {
        // Update the adjacency list
        AdjListNode* newNode = newAdjListNode(dest);
        AdjListNode* curNode = array[src].head;
        bool flag = false;
        if (curNode) {
            while (curNode -> next) {
                if (src == curNode -> dest) {
                    flag = true;
                    break;
                }
                curNode = curNode -> next;
            }
        }
        if (!curNode)
            array[src].head = newNode;
        else if (!flag)
            curNode -> next = newNode;

        newNode = newAdjListNode(src);
        curNode = array[dest].head;
        flag = false;
        if (curNode) {
            while (curNode -> next) {
                if (dest == curNode -> dest) {
                    flag = true;
                    break;
                }
                curNode = curNode -> next;
            }
        }
        if (!curNode)
            array[dest].head = newNode;
        else if (!flag)
            curNode -> next = newNode;

        // Update the adjacency matrix
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

public:

    Graph(string filename) {
        adjMatrix = new int*[nodes];
        fstream f(filename, ios::in);
        f >> nodes >> edges;
        array = new AdjList[nodes];
        for (int i = 0 ; i < nodes ; ++i) {
            array[i].head = NULL;
            adjMatrix[i] = new int[nodes];
            for (int j = 0 ; j < nodes ; ++j)
                adjMatrix[i][j] = 0;
        }
        for (int i = 0 ; i < edges ; ++i) {
            int src, dest;
            f >> src >> dest;
            addEdge(src, dest);
        }
        f.close();

        cout << endl << "Graph has been constructed from " << filename << " file" << endl;
        cout << "Number of nodes = " << nodes << endl;
        cout << "Number of edges = " << edges << endl;
        cout << endl;
    }

    void printGraph();
    void printAdjacencyMatrix();
    void breadthFirstSearch();
    void depthFirstSearch();
};

void Graph::printGraph() {
    for (int i = 0; i < nodes; ++i) {
        AdjListNode* curNode = array[i].head;
        cout << "Vertex " << i;
        while (curNode) {
            cout << " -> " << curNode->dest;
            curNode = curNode->next;
        }
        cout << endl;
    }
}

void Graph::printAdjacencyMatrix() {
    for (int i = 0 ; i < nodes ; ++i) {
        for (int j = 0 ; j < nodes ; ++j)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

void Graph::breadthFirstSearch() {
    bool visited[nodes] = {0};
    Queue bfs_queue;
    bfs_queue.enqueue(0);
    while (!bfs_queue.isEmpty()) {
        int cur = bfs_queue.dequeue();
        if (visited[cur] == 0) {
            visited[cur] = 1;
            AdjListNode* curNode = array[cur].head;
            while (curNode) {
                if (!visited[curNode -> dest]) {
                    bfs_queue.enqueue(curNode -> dest);
                }
                curNode = curNode -> next;
            }
            cout << cur << " ";
        }
    }
    cout << endl;
}

void Graph::depthFirstSearch() {
    bool visited[nodes] = {0};
    Stack dfs_stack;
    dfs_stack.push(0);
    while (!dfs_stack.isEmpty()) {
        int cur = dfs_stack.pop();
        if (visited[cur] == 0) {
            visited[cur] = 1;
            AdjListNode* curNode = array[cur].head;
            while (curNode) {
                if (!visited[curNode -> dest]) {
                    dfs_stack.push(curNode -> dest);
                }
                curNode = curNode -> next;
            }
            cout << cur << " ";
        }
    }
    cout << endl;
}

int main() {

    Graph graph("graph_input.txt");

    int ch;

    cout << "1. Adjacency List" << endl;
    cout << "2. Adjacency Matrix" << endl;
    cout << "3. Breadth First Search" << endl;
    cout << "4. Depth First Search" << endl;
    cout << "5. Exit" << endl;

    do {
        cout << endl << "Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "\nAdjacency List:" << endl;
                graph.printGraph();
                break;
            case 2:
                cout << "\nAdjacency Matrix:" << endl;
                graph.printAdjacencyMatrix();
                break;
            case 3:
                cout << "Breadth First Search: ";
                graph.breadthFirstSearch();
                break;
            case 4:
                cout << "Depth First Search: ";
                graph.depthFirstSearch();
                break;
            case 5:
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (ch != 5);

    return 0;
}