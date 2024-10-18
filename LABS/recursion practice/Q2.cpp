#include<iostream>
#include<vector>
using namespace std;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};


bool isValid(int i, int j, int n, int m, vector<vector<char>>& field){
    return (i >= 0 && i < n && j >= 0 && j < m && field[i][j] == 'T');
}


int exploreForest(int i, int j, int n, int m, vector<vector<char>>& field){
    if(!isValid(i, j, n, m, field)){
        return 0;
    }

    field[i][j] = 'W';
    
    int sizeOfForest = 1; 

    for(int k = 0; k < 4; k++){
        int newRow = i + row[k];
        int newCol = j + col[k];

        sizeOfForest += exploreForest(newRow, newCol, n, m, field);
    }

    return sizeOfForest; 
}

int largestForest(vector<vector<char>>& field){
    int n = field.size();
    int m = field[0].size();
    int largestSize = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(field[i][j] == 'T'){
                int forestSize = exploreForest(i, j, n, m, field);  
                largestSize = max(largestSize, forestSize);  
            }
        }
    }
    
    return largestSize; 
}

int main() {
    vector<vector<char>> field = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}
    };

    cout << "Output: " << largestForest(field) << endl;

    return 0;
}
