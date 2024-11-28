/*
2 methods:
    1- Adjacency Matrix  - 2d array
    2- Adjacency List  - Linked list
*/

/*
- Directed Graphs
- Unfirected raphs
*/

/*
Given Information:
    - no of vertices
    - edges
    - vertex connected to other vertices and their edges
    for eg: vertex:{0,1,2,3,4} = 5
            edges:{{0,1},{1,2},{0,2},{2,4},{3,4},{1,3}}
*/

/*
Adjacency Matrix: using 2D array

1. Undirected - Unweighted Graph:
    1 edge hai, 0 edge nahi hai
frome above example:
      0 1 2 3 4
    0 0 1 1 0 0
    1 1 0 1 1 0
    2 1 1 0 0 1
    3 0 1 0 0 1
    4 0 0 1 1 0

2. Undirected - Weighted Graph:
    instead of 0 or 1, we will add weights of edges

      0 1 2 3 4
    0 0 3 4 0 0
    1 3 0 5 2 0
    2 4 5 0 0 6
    3 0 2 0 0 7
    4 0 0 6 7 0

3. Directed Graph - Unweighted:

    edges:{{0,1},{1,2},{0,2},{2,4},{4,3},{3,1}}
      0 1 2 3 4
    0 0 1 1 0 0
    1 0 0 1 2 0
    2 0 0 0 0 1
    3 0 1 0 0 0
    4 0 0 0 1 0

4. Directed - Weighted Graph:
  similar concept
*/

// code:
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int vertex, edges;
  cin >> vertex >> edges;

  // Undirected - Unweight
  vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0)); // row = vertex and col = vertex. Intialized all indexes to 0

  int u, v;
  for (int i = 0; i < edges; i++)
  { // input edges
    cin >> u >> v;
    AdjMat[u][v] = 1; // filling matrix
    AdjMat[v][u] = 1;
  }

  // print
  for (int i = 0; i < vertex; i++)
  {
    for (int j = 0; j < vertex; j++)
    {
      cout << AdjMat[i][j] << " ";
    }
    cout << endl;
  }
}

// Undirected - Weighted
void undirectedWeighted(int vertex, int edges)
{
  vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

  int u, v, weight;
  for (int i = 0; i < edges; i++)
  { // input edges
    cin >> u >> v >> weight;
    AdjMat[u][v] = weight; // filling matrix
    AdjMat[v][u] = weight;
  }
}

// Directed - Unweighted
void directedUnweighted(int vertex, int edges)
{
  vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

  int u, v;
  for (int i = 0; i < edges; i++)
  { // input edges
    cin >> u >> v;
    AdjMat[u][v] = 1; // filling matrix
  }
}

// make changes for directed - weighted as well

/*
Adjacency List: using Linked List / Vector - similar to linear probing in hashing

1. Undirected - Unweighted:
  create an array of size = no of vertices
  then link all the edges using linked list or vector

  for eg: vertex:{0,1,2,3,4} = 5
          edges:{{0,1},{1,2},{0,2},{2,4},{3,4},{1,3}}

  0 -> 1 -> 2
  1 -> 0 -> 3 -> 2
  2 -> 0 -> 1 -> 4
  3 -> 1
  4 -> 2 -> 3

2. Unidirected - Weighted: we will make a pair of vertex and weights for representing each edge

  0 -> (1,6) -> (2,4)
  1 -> (0) -> (3) -> (2)
  2 -> (0) -> (1) -> (4)
  3 -> (1)
  4 -> (2) -> (3)
*/

// code

// undirected graph(no weight)
int main()
{
  int vertex, edges;
  cin >> vertex >> edges;

  vector<int> AdjList[vertex]; // size = no of vertex

  int u, v;
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }

  // print the list
  for (int i = 0; i < vertex; i++)
  {
    cout << i << " -> ";
    for (int j = 0; i < vertex; j++)
    {
      cout << AdjList[i][j];
    }
    cout << endl;
  }
}

void undirectedWeighted(int vertex, int edges)
{

  vector<pair<int, int>> AdjList[vertex]; // size = no of vertex

  int u, v, weight;
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    AdjList[u].push_back(make_pair(v, weight));
    AdjList[v].push_back(make_pair(u, weight));
  }

  // print the list
  for (int i = 0; i < vertex; i++)
  {
    cout << i << " -> ";
    for (int j = 0; i < vertex; j++)
    {
      cout << AdjList[i][j].first << "," << AdjList[i][j].second << " ";
    }
    cout << endl;
  }
}

// make changes for directed graphs