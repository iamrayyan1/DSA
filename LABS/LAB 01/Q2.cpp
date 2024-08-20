#include<iostream>
#include<cstring>
using namespace std;

class Exam{
    private:
        char *studentName;
        char *examDate;
        int *score;

    public:
        Exam(const char* name, const char* date, int sc){
            studentName = new char[strlen(name) + 1]; 
            strcpy(studentName, name);

            examDate = new char[strlen(date) + 1];  
            strcpy(examDate, date);

            score = new int(sc);
        }
        ~Exam(){
            delete[] studentName;  
            delete[] examDate;
            delete score;     
        }

        void print(){
            cout << "Student Name: " << studentName << endl;
            cout << "Exam Date: " << examDate << endl;
            cout << "Score: " << *score << endl;
        }

};

int main(){
    Exam exam1("Rayyan", "15-06-23", 98);
    Exam exam2 = exam1;

    cout << "Exam 1 Details:\n";
    exam1.print();
    cout << "Exam 2 Details:\n";
    exam2.print();
}
