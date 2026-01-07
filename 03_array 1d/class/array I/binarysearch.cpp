// only for sorted array agar sprted nhi hai toh phele sort kerna padega
#include <iostream>
using namespace std;
int binarysearch(int *arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid; // key found at mid
        }

        else if (arr[mid] < key)
        {
            start = mid + 1; // 2nd half
        }
        else
        {
            end = mid - 1; // first half
        }
    }
    return -1; // if key dnt exist
}
int main()
{
    int arr[] = {2, 4, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);
    int key = 12;
    cout << binarysearch(arr, n, key) << endl;
}