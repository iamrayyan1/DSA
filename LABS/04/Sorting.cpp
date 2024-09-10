#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool flag = 0;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
    return;
}

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int> &arr)
{

    int gap = arr.size() / 2;

    while (gap > 0)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
        gap /= 2;
    }
}

void combSort(vector<int> &arr)
{
    float sf = 1.3;
    int gap = arr.size();
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        gap = gap / sf;
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < arr.size(); i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    vector<int> arr = {15, 20, 10, 33, 88, 44};

    bubbleSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

  
    arr = {15, 20, 10, 33, 88, 44};
    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

  
    arr = {15, 20, 10, 33, 88, 44};
    insertionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {15, 20, 10, 33, 88, 44};
    shellSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {15, 20, 10, 33, 88, 44};
    combSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
