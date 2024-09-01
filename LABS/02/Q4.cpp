/*
You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
To efficiently store and present this data, which type of array structure would you employ? implement a solution
using the chosen array structure to display the GPAs of the core courses for each department.
*/


#include<iostream>
using namespace std;

int main(){
    int numDepartments = 4;
    float** gpas = new float*[numDepartments];

    gpas[0] = new float[3]; 
    gpas[1] = new float[4]; 
    gpas[2] = new float[2];
    gpas[3] = new float[1]; 


    cout << "Enter GPAs for Software Engineering: ";
    for (int i = 0; i < 3; i++){
        cin >> gpas[0][i];
    }

    cout << "Enter GPAs for Artificial Intelligence: ";
    for (int i = 0; i < 4; i++){
        cin >> gpas[1][i];
    }

    cout << "Enter GPAs for Computer Science";
    for (int i = 0; i < 2; i++){
        cin >> gpas[2][i];
    }

    cout << "Enter GPA for Data Science: ";
    for (int i = 0; i < 1; i++){
        cin >> gpas[3][i];
    }



    cout << "\nGPAs for each department's core courses:\n";

    cout << "Software Engineering: ";
    for (int i = 0; i < 3; i++){
        cout << gpas[0][i] << " ";
    }
    cout << endl;

    cout << "Artificial Intelligence: ";
    for (int i = 0; i < 4; i++){
        cout << gpas[1][i] << " ";
    }
    cout << endl;

    cout << "Computer Science: ";
    for (int i = 0; i < 2; i++){
        cout << gpas[2][i] << " ";
    }
    cout << endl;

    cout << "Data Science: ";
    for (int i = 0; i < 1; i++){
        cout << gpas[3][i] << " ";
    }
    cout << endl;


    for (int i = 0; i < numDepartments; i++){
        delete[] gpas[i];
    }
    delete[] gpas;

    return 0;
}


