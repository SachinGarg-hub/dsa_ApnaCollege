// Fractional Knapsack Problem using Greedy Approach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<double, int> a, pair<double, int> b)
{
    return a.first > b.first; // Sort in descending order of value-to-weight ratio
}
int fractionalKnapsack(int capacity, vector<int> weights, vector<int> values)
{
    int n = values.size();
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(double)values[i] / weights[i], i};
    }
    sort(ratio.begin(), ratio.end(), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;
        int idx = ratio[i].second; // Original index of the item
        if (weights[idx] <= capacity)
        {
            capacity -= weights[idx];
            totalValue += values[idx];
        }
        else
        {
            totalValue += ratio[i].first * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}
int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    double maxValue = fractionalKnapsack(capacity, weights, values);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}