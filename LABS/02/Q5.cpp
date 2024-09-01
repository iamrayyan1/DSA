/*
5. You're developing a program to manage a seating chart for a conference held in a hall with multiple rows
of seats. Each row has a different seat capacity. To efficiently handle the seating arrangements, you decide to use
a dynamic array. Implement a C++ code that allocates memory for the seating chart and allows attendees' names
to be inputted for each seat. Choose and implement the appropriate type of dynamic array for this scenario.
*/


#include<iostream>
using namespace std;

int main(){
    int numRows;
    cout << "Enter the number of rows in the hall: ";
    cin >> numRows;


    string** seatingChart = new string*[numRows];
    int* seatsPerRow = new int[numRows]; 


    for (int i = 0; i < numRows; i++){
        cout << "Enter the number of seats in row " << i + 1 << ": ";
        cin >> seatsPerRow[i];
        seatingChart[i] = new string[seatsPerRow[i]];



        for (int j = 0; j < seatsPerRow[i]; j++){
            seatingChart[i][j] = "";
        }
    }



    cout << "\nEnter the attendees' names for each seat.\n";
    for (int i = 0; i < numRows; i++){
        cout << "\nRow " << i + 1 << ":\n";
        for (int j = 0; j < seatsPerRow[i]; j++){
            cout << "Enter name for seat " << j + 1 << ": ";
            cin >> seatingChart[i][j];
        }
    }



    cout << "\nSeating Chart:\n";
    for (int i = 0; i < numRows; i++){
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seatsPerRow[i]; j++){  
            if (seatingChart[i][j] != ""){
                cout << seatingChart[i][j] << " ";
            } 
            else{
                cout << "Empty ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < numRows; i++){
        delete[] seatingChart[i];
    }
    delete[] seatingChart;
    delete[] seatsPerRow; 

    return 0;
}
