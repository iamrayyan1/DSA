#include<iostream>
#include<vector>
using namespace std;

//Q1:  perfect sum Problem

// create subsets of array which sum is equal to the target sum

 

 // Q2: Target Sum Problem







// Q3: Permutation (All combinations)

// TC = n * n ! -> O(n*n!)
// SC = O(n)


int permutation(int arr[], vector<vector<int>> &ans, vector<int>&temp, vector<bool>&visited){
    
    if(visited.size() == temp.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=0; i<visited.size(); i++){
        if(visited[i]==0){
            visited[i] == 1;
            temp.push_back(arr[i]);
            permutation(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main(){
    int arr[] = {1,2,3,4};
    vector<vector<int>> ans;
    vector<int>temp;
    vector<bool>visited(3,0);
    permutation(arr, ans, temp, visited);


    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }
    }
}
 


// without taking extra memory of temp and visited vectors
// using swapping to solve the problem

int permutation(vector<int>&arr, vector<vector<int>>ans, int index){

    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }
    
    for(int i=index; i<arr.size(); i++){
        swap(arr[i], arr[index]);
        permutation(arr, ans, index+1);
        swap(arr[i], arr[index]);
    }
}



// Q4: Permutation with repetition



// Q5: Ways to Sum N 




// Q6: Tower of Hanoi

// n number of disks
// 3 rods -> source, helper and destination
// number of steps to solve the problem
/*
Few Conditions:
1. 1 baar mei 1 hi disk ko move ker sakte and woh top wali hogi
2. choti disk ke ooper bari disk ko nahi rakh sakte
*/

// first, middle, last  or  from , to , aux

void ToH(int n, int source, int help, int dest){

    if(n==1){
        cout << "Move disk" << n << "from" << source << "to" << dest;
        return;
    }

    ToH(n-1, source, dest, help);

    cout << "Move disk" << n << "from" << source << "to" << dest;

    ToH(n-1, help, source, dest);
}

// TC = O(2^n - 1)
// SC = O(n)




// Q7: Josephus Problem -> Predict the winner

// conditions 

int winner(vector<bool>person, int n, int index, int person_left, int k){

    if(person_left==1){
        for(int i=0; i<n; i++){
            if(person[i]==0)
              return i;  
        }
    }

    int kill = (k-1)%person_left;
    
    while(kill--){
        index = (index+1)%n;
        while(person[index]==1){
            index = (index+1)%n;
        }
    }
    person[index] == 1;

    while(person[index]==1){
        index = (index+1)%n;
    }

    winner(person, n, index, person_left-1, k);
}

// TC = O(n^2)
// SC = O(n)


// more optimize approach

int winner(int n, int k){
    if(n==1){
        return 0;
    }

    return(winner(n-1, k) + k) % n;
}

// make pattern



// Q8: Rat in a Maze Problem

// apply recursion on 2D array

// UP : U
// DOWN : D
// LEFT : L
// RIGHT : R 


int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};
string dir = "UDLR";

bool valid(int i, int j, int n){
    return i>=0 && j>=0 && i<n && j<n;
}

int total(vector<vector<int>> &matrix, int i, int j, int n, vector<string> &path, vector<vector<string>> &ans, vector<vector<bool>> &visited){

    if(i==n-1 && j==n-1){     // last row and last col
        ans.push_back(path);
        return;
    }

    visited[i][j] == 1;

    // up
    if(valid(i-1, j, n) && matrix[i-1][j] && !visited[i-1][j]){
        path.push_back("U");
        total(matrix, i-1, j, n, path, ans, visited);
    }

    // down
    if(valid(i+1, j, n) && matrix[i+1][j] && !visited[i+1][j]){
        path.push_back("D");
        total(matrix, i+1, j, n, path, ans, visited);
    }

    // Left
    if(valid(i, j-1, n) && matrix[i][j-1] && !visited[i][j-1]){
        path.push_back("L");
        total(matrix, i, j-1, n, path, ans, visited);
    }

    // Right
    if(valid(i, j+1, n) && matrix[i][j+1] && !visited[i][j+1]){
        path.push_back("R");
        total(matrix, i, j+1, n, path, ans, visited);
    }

    // instead of writing 4 different conditions we can summarise them into one for loop using
    for(int k=0; k<4; k++){

        if( valid(i+row[k], j+col[k], n) && matrix[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]]){
            path.push_back(dir[k]);

            total(matrix, i+row[k], j+col[k], n, path, ans, visited);

            path.pop_back();
        }
    }
    visited[i][j] = 0;
}


// TC = O(3^n^2)
// SC = O