#include "iostream"
using namespace std;

int main(){
    bool** grid = new bool*[5];
    for (size_t i = 0; i < 5; i++){
        grid[i] = new bool[5]{false};
    }

    grid[0][1] = true; grid[0][3] = true;
    grid[0][4] = true; grid[1][0] = true; grid[1][2] = true;
    grid[1][4] = true; grid[2][1] = true; grid[3][0] = true;
    grid[3][4] = true; grid[4][0] = true; grid[4][1] = true;
    grid[4][3] = true;


    cout << "   ";
    for (size_t j = 0; j < 5; j++){
        cout << j << "   ";
    }
    cout << endl;


    for (size_t i = 0; i < 5; i++){
        cout << i << " ";
        for (size_t j = 0; j < 5; j++){
            cout << "[" << grid[i][j] << "] ";
        }
        cout << endl;
    }

    int person1 = 2, person2 = 4; 
    bool flag = false;
    int frnd;
    for (size_t i = 0; i < 5; i++){
        if (grid[person1][i] && grid[person2][i]){
            flag = true;
            frnd = i;
        }
    }



    if (flag)
        cout << person1 << " & " << person2 << " are friends with " << frnd << endl;
    else
        cout << "No mutual friend found" << endl;

    for (size_t i = 0; i < 5; i++){
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
