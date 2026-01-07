#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // Sort based on second element of the pair
}
int maxChainlen(vector<pair<int, int>> &pairs)
{
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    int ans = 1;
    int currEnd = pairs[0].second;
    for (int i = 1; i < n; i++)
    {
        if (pairs[i].first > currEnd)
        {
            ans++;
            currEnd = pairs[i].second;
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> pairs = {{3, 4}, {1, 2}, {5, 0}, {2, 3}};
    int length = maxChainlen(pairs);
    cout << "Length of Longest Chain = " << length << endl;
    return 0;
}