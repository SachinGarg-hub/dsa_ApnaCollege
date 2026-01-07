/*Apply Merge sort to sort an array of Strings.
(Assume that all the characters in all the Strings are in lower case).
input arr={"sun","earth,"mars","mercury"}
Output: arr={"earth","mars","mercury","sun"}
*/

#include <iostream>
#include <string>
using namespace std;

// Merge function
void merge(string arr[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;

    string *left = new string[n1];
    string *right = new string[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[si + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = si;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        { // compare strings lexicographically
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

// Merge sort function
void mergeSort(string arr[], int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

// Function to print array
void printArray(string arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    string arr[] = {"sun", "earth", "mars", "mercury"};
    int n = 4;

    cout << "Before Sorting: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}
