#include <iostream>
using namespace std;

class Participants{
    public:
    string name;
    int time;
    Participants() {}
    Participants(string name, int time): name(name) , time(time) {}
};


void merge(Participants arr[] , int low , int mid , int high){
    int n1= mid-low+1;
    int n2 = high - mid;

    Participants* left = new Participants[n1];
    Participants* right = new Participants[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[low+i]; 
    for(int i=0; i<n2;i++)
        right[i] = arr[mid+1+i];
    

    int i = 0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2){
        if(left[i].time < right[j].time){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}



void mergeSort(Participants arr[] , int low, int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}



int main(){
   const int p = 10;
   Participants part[p];

    for(int i=0;i<p;i++){
        string name;
        int time;

        cout<<"Enter name and finish time for runner " << i << ": ";
        cin >> name;
        cin >> time;
        part[i] = Participants(name,time);
   }


   mergeSort(part,0,p-1);
   cout << "Top 5 fastest runners: " << endl;
   for(int i=0;i<5;i++){
    cout<< i+1 << ". " << part[i].name << " - " << part[i].time << " seconds" << endl;
   }
}