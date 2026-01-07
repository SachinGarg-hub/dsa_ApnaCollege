// Activity Selection Problem using Greedy Algorithm
// solve max meeting in a room on leetcode
#include <iostream>
#include <vector>
using namespace std;
int maxActivitys(vector<int> start, vector<int> end)
{
    int n = start.size();
    int count = 1; // first activity is always selected
    int currEnd = end[0];
    for (int i = 1; i < n; i++)
    {
        if (start[i] >= currEnd) // non-overlapping activity
        {
            count++;
            currEnd = end[i];
        }
    }
    return count;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9}; // ans 4
    cout << "Maximum number of activities: " << maxActivitys(start, end) << endl;
    return 0;
}