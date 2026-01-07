// wap to find last occurrence of an element in a vector
#include <iostream>
#include <vector>
using namespace std;
int lastoccurrence(vector<int> arr, int key, int i)
{
    if (i == arr.size())
    {
        return -1;
    }
    int lastidx = lastoccurrence(arr, key, i + 1);
    if ((lastidx == -1) && (arr[i] == key))
    {

        return i;
    }
    return lastidx;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 3};
    cout << lastoccurrence(arr, 3, 0) << endl;
}