#include <iostream>
#include <vector>
using namespace std;

bool isSymmetric(vector<vector<int>>& AdjMat){
    for (int i = 0; i < AdjMat.size(); i++)
    {
        for (int j = 0; j < AdjMat.size(); j++)
        {
            if (AdjMat[i][j] != AdjMat[j][i])
            {
                return false;
            }
        }
    }
    return true;
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

int main()
{
    vector<vector<int>> AdjMat = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};

    cout << "Adjacency Matrix:" << endl;
    displayAdjMatrix(AdjMat);

    if(isSymmetric(adjMatrix))
    {
        cout << "symmetric" << endl;
    } else
    {
        cout << "not symmetric" << endl;
    }
}
