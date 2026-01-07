/* subarray is continuosu part of an array
no. of subarray = n*(n+1)/2
TC: O(n^3)*/

#include <iostream>
using namespace std;
void printSubarrays(int *arr, int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // cout << "(" << start << "," << end << ") ";
            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    printSubarrays(arr, n);
    return 0;
}