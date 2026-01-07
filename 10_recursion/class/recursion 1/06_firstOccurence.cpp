// wap to find first occurrence of an element in a vector
#include <iostream>
#include <vector>
using namespace std;
int firstoccurrence(vector<int> arr, int i, int key)
{
    if (i == arr.size())
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return firstoccurrence(arr, i + 1, key);
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 3};
    cout << firstoccurrence(arr, 0, 3) << endl;
}