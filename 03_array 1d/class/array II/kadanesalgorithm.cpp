#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum3(int *arr, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum = " << maxSubarraySum3(arr, n) << endl;
    return 0;
}
