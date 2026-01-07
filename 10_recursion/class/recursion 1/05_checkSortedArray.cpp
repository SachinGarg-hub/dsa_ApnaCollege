#include <iostream>
using namespace std;
bool checkSorted(int *arr, int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }
    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    return checkSorted(arr, n, i + 1);
}
int main()
{
    int arr[5] = {1, 7, 8, 9, 10};
    int arr1[5] = {1, 7, 9, 8, 10};
    int size = sizeof(arr) / sizeof(int);
    cout << checkSorted(arr, size, 0) << endl;
    ;
    cout << checkSorted(arr1, size, 0) << endl;
}