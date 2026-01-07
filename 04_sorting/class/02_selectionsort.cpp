// pick the smallest & put in the beignning..

#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void SelectionSort(int arr[], int n)
{
    int minIdx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr, n);
}
int main()
{
    int arr[6] = {5, 4, 1, 3, 2};
    int n = 5;
    SelectionSort(arr, n);
}