// we are given an infinite supply of coins of denominations 1,2 , 5, 10, 25, 50, 100,500,2000
// we need to find the minimum number of coins required to make a given value n
// we will use a greedy approach to solve this problem
#include <iostream>
#include <vector>
using namespace std;
int minCoins(vector<int> coins, int v)
{
    int n = coins.size();
    int ans = 0;
    for (int i = 0; i < n && v > 0; i++)
    {
        if (v >= coins[i])
        {
            ans += v / coins[i];
            v = v % coins[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> coins = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n;
    cout << "Enter the value to make change for: ";
    cin >> n;
    int result = minCoins(coins, n);
    cout << "Minimum number of coins required: " << result << endl;
    return 0;
}
