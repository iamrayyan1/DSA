#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Function to perform BFS traversal
void BFS(int start, const vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adjList[node].size(); ++i)
        {
            int neighbor = adjList[node][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Function to perform DFS traversal (iterative)
void DFS_Iterative(int start, const vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    cout << "DFS Traversal (Iterative): ";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors in reverse order to maintain correct traversal order
            for (int i = adjList[node].size() - 1; i >= 0; --i)
            {
                int neighbor = adjList[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

// Function to perform DFS traversal (recursive helper)
void DFS_Recursive_Helper(int node, const vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adjList[node].size(); ++i)
    {
        int neighbor = adjList[node][i];
        if (!visited[neighbor])
        {
            DFS_Recursive_Helper(neighbor, adjList, visited);
        }
    }
}

// Function to perform DFS traversal (recursive)
void DFS_Recursive(int start, const vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);

    cout << "DFS Traversal (Recursive): ";
    DFS_Recursive_Helper(start, adjList, visited);
    cout << endl;
}

int main()
{
    // Example adjacency list representation of a graph
    vector<vector<int>> adjList = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 4},    // Neighbors of node 2
        {1, 5},    // Neighbors of node 3
        {1, 2, 5}, // Neighbors of node 4
        {3, 4}     // Neighbors of node 5
    };

    int startNode = 0; // Starting node for traversals

    cout << "Graph Traversals starting from node " << startNode << ":" << endl;

    // Perform BFS
    BFS(startNode, adjList);

    // Perform DFS (iterative)
    DFS_Iterative(startNode, adjList);

    // Perform DFS (recursive)
    DFS_Recursive(startNode, adjList);

    return 0;
}
