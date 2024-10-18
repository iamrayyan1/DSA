#include<iostream>
#include<vector>
using namespace std;

bool valid(int i, int j, int n){
    return i >= 0 && j >= 0 && i < n && j < n;
}

void total(vector<vector<int>> &matrix, int i, int j, int n, string &path, vector<string> &ans, vector<vector<bool>> &visited){
    if(i == n - 1 && j == n - 1){    // last row and last col 
        ans.push_back(path);          
        return;
    }

    visited[i][j] = 1;              

    // Up
    if(valid(i - 1, j, n) && matrix[i - 1][j] && !visited[i - 1][j]){
        path.push_back('U');
        total(matrix, i - 1, j, n, path, ans, visited);
        path.pop_back();
    }

    // Down
    if(valid(i + 1, j, n) && matrix[i + 1][j] && !visited[i + 1][j]){
        path.push_back('D');
        total(matrix, i + 1, j, n, path, ans, visited);
        path.pop_back();
    }

    // Left
    if(valid(i, j - 1, n) && matrix[i][j - 1] && !visited[i][j - 1]){
        path.push_back('L');
        total(matrix, i, j - 1, n, path, ans, visited);
        path.pop_back();
    }

    // Right
    if(valid(i, j + 1, n) && matrix[i][j + 1] && !visited[i][j + 1]){
        path.push_back('R');
        total(matrix, i, j + 1, n, path, ans, visited);
        path.pop_back();
    }

    visited[i][j] = 0;
}

vector<string> findAllPaths(vector<vector<int>> &matrix, int n){
    vector<string> ans;  
    vector<vector<bool>> visited(n, vector<bool>(n, false));  
    string path = "";  

    if(matrix[0][0] == 1){ 
        total(matrix, 0, 0, n, path, ans, visited);
    }

    return ans;  // return all found paths
}

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = matrix.size();
    vector<string> paths = findAllPaths(matrix, n); 

    if(paths.empty()){
        cout << "No path found." << endl;
    } else {
        for(int i = 0; i < paths.size(); i++){
            cout << paths[i] << endl;  
        }
    }

    return 0;
}
