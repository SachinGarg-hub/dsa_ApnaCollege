// larger  elemengts come to end by aswapping with adjacents
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

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // assending
            // if (arr[j] < arr[j + 1]) //desending
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return; // array is already sorted
        }
    }
    print(arr, n);
}
int main()
{
    int arr[6] = {5, 4, 1, 3, 2};
    int n = 5;
    bubbleSort(arr, n);
}