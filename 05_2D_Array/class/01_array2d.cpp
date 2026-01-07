#include <iostream>
using namespace std;
int main()
{
    int students[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr[3][4];
    int n = 3, m = 4;
    // input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}