#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixToList(const vector<vector<int>> &AdjMat)
{
    vector<vector<int>> AdjList(AdjMat.size());
    for (int i = 0; i < AdjMat.size(); ++i)
    {
        for (int j = 0; j < AdjMat.size(); ++j)
        {
            if (AdjMat[i][j] == 1)
            {
                AdjList[i].push_back(j);
            }
        }
    }
    return AdjList;
}

vector<vector<int>> listToMatrix(const vector<vector<int>> &AdjList)
{
    vector<vector<int>> AdjMat(AdjList.size(), vector<int>(AdjList.size(), 0));
    for (int i = 0; i < AdjList.size(); ++i)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            AdjMat[i][AdjList[i][j]] = 1;
        }
    }
    return AdjMat;
}

void printAM(const vector<vector<int>> &AdjMat)
{
    for (int i = 0; i < AdjMat.size(); i++)
    {
        for (int j = 0; j < AdjMat.size(); j++)
        {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void printAL(const vector<vector<int>> &AdjList)
{
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};

    cout << "Adjacency Matrix:" << endl;
    printAM(adjMatrix);

    vector<vector<int>> adjList = matrixToList(adjMatrix);
    cout << "\nAdjacency List:" << endl;
    printAL(adjList);

    vector<vector<int>> convertedMatrix = listToMatrix(adjList);
    cout << "\nAdjacency Matrix:" << endl;
    printAM(convertedMatrix);

    return 0;
}
