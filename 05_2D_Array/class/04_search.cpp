// Search in a sorted Matrix
//  search for a key in row wise and col wise sorted matrix
// Do leetcode 74 and 240 for better explaination
#include <iostream>
using namespace std;
void Search1(int mat[][4], int n, int m, int key)
{
    // brute force (linear search ) TC=>O(m*n)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == key)
            {
                cout << key << " is present at " << i << "," << j << endl;
            }
        }
    }
}

// slightly opitmized binary search row/col tc=>O(nlogm)/(mlogn)
bool searchMatrix(int matrix[][4], int n, int m, int target)
{
    // leetcode 74
    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // mid ko 2D index me convert karna:
        int row = mid / m; // kaunsi row
        int col = mid % m; // kaunsa column
        int val = matrix[row][col];

        if (val == target)
        {
            cout << target << " at" << row << " " << col << endl;
            return true;
        }
        else if (val < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
bool stairCase(int mat[][4], int n, int m, int target)
{
    // leetcode 240
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == target)
        {
            cout << "found at cell (" << i << "," << j << ")" << endl;
            return true;
        }
        else
        {
            // left
            if (mat[i][j] > target)
            {
                j--;
            }
            else
            {
                // dowm
                i++;
            }
        }
    }
    return false;
}

int main()
{
    int mat[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 45}};
    Search1(mat, 4, 4, 33);
    return 0;

    int mat2[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    searchMatrix(mat2, 3, 4, 16);
}