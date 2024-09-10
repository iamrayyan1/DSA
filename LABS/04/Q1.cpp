#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            cout << "Found at index " << i + 1 << endl;
            return 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> &arr, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    if (start == end)
    {
        if (arr[start] == arr[end])
        {
            return start;
        }
        return -1;
    }

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == x)
        {
            cout << "Found at index " << mid + 1 << endl;
            return 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(vector<int> &arr, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int pos = -1;

    if (start == end)
    {
        if (arr[start] == arr[end])
        {
            return start;
        }
        return -1;
    }

    while (start <= end && arr[start] <= x && arr[end] >= x)
    {
        pos = start + ((x - arr[start]) * (end - start) / (arr[end] - arr[start]));

        if (arr[pos] == x)
        {
            cout << "Found at index " << pos + 1 << endl;
            return 1;
        }
        else if (arr[pos] < x)
        {
            start = pos + 1;
        }
        else
        {
            end = pos - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 15, 20, 33, 44, 88};
    int target = 44;

    // Linear Search
    linearSearch(arr, target);

    // Binary Search
    binarySearch(arr, target);

    // Interpolation Search
    interpolationSearch(arr, target);
}
