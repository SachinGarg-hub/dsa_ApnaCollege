#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 5, 50, 10, 34, 45};
    int n = 6;
    int key = 10;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            cout << key << " is at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << key << " not found" << endl;
    }

    return 0;
}
