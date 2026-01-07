#include <iostream>
using namespace std;
void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // with extra space
    int arr[10] = {5, 4, 3, 9, 2};
    int n = 5;
    int CopyArr[n];
    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        CopyArr[i] = arr[j];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = CopyArr[i];
    }
    printArr(arr, n);
}