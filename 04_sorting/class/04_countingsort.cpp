// Counting Sort using frequency count
#include <iostream>
#include <climits>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n)
{
    int freq[100000];
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    int j = 0;
    for (int i = minVal; i <= maxVal; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }

    print(arr, n);
}

int main()
{
    int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    countingSort(arr, n);

    return 0;
}
