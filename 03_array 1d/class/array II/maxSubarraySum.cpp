
#include <iostream>
#include <climits>
using namespace std;
void maxsubarray1(int *arr, int n)
{
    // brute force approach
    // TC =O(n^3)
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum += arr[i];
            }
            cout << currSum << ",";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }
    cout << "Maximum sum of subarray is " << maxSum << endl;
}
void maxSubArray(int *arr, int n)
{
    // slightly optimized
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Maximum sum of subarray is " << maxSum << endl;
}
int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    maxsubarray1(arr, n);
    maxSubArray(arr, n);
    return 0;
}