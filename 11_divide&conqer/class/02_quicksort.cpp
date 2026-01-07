#include <iostream>
#include <vector>
using namespace std;

// Partition function - first element as pivot
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // first element pivot
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        // i ko tab tak badhao jab tak pivot se bada element na mil jaye
        while (i <= high && arr[i] <= pivot)
            i++;

        // j ko tab tak ghatao jab tak pivot se chhota element na mil jaye
        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]); // galat jagah wale elements ko swap karo
    }

    // finally pivot ko correct jagah par daalo
    swap(arr[low], arr[j]);
    return j; // pivot ka final position return karo
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // pivot position find karo
        quickSort(arr, low, pi - 1);        // left side sort karo
        quickSort(arr, pi + 1, high);       // right side sort karo
    }
}

// Function to print the array/vector
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Before Sorting: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "After Sorting: ";
    printArray(arr);

    return 0;
}
