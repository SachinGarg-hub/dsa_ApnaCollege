#include <iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m)
{
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol)
    {
        // top row
        for (int j = scol; j <= ecol; j++)
        {
            cout << matrix[srow][j] << " ";
        }

        // right column
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << matrix[i][ecol] << " ";
        }

        // bottom row
        if (srow < erow) // to avoid duplicate row
        {
            for (int j = ecol - 1; j >= scol; j--)
            {
                cout << matrix[erow][j] << " ";
            }
        }

        // left column
        if (scol < ecol) // to avoid duplicate column
        {
            for (int i = erow - 1; i > srow; i--)
            {
                cout << matrix[i][scol] << " ";
            }
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }
}

int main()
{
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    spiralMatrix(matrix, 4, 4);
    return 0;
}
