// absolute minimum difference between any two elements in an array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size();
    int absDiff = 0;
    for (int i = 0; i < n; i++)
    {
        absDiff += abs(a[i] - b[i]);
    }
    cout << "Absolute Minimum Difference = " << absDiff << endl;
    return 0;
}