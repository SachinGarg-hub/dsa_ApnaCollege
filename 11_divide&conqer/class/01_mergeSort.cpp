#include <iostream>
#include <vector>
using namespace std;

// Function to print the array/vector
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Merge function
void merge(vector<int> &arr, int si, int mid, int ei)
{
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= ei)
        temp.push_back(arr[j++]);

    int x = 0;
    for (int idx = si; idx <= ei; idx++)
    {
        arr[idx] = temp[x++];
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);     // left part
    mergeSort(arr, mid + 1, ei); // right part
    merge(arr, si, mid, ei);
}

// Main function
int main()
{
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    cout << "Original array: ";
    printArray(arr); // before sorting

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr); // after sorting

    return 0;
}
