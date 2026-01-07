// job sequencing problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProfit(vector<pair<int, int>> &jobs, int n)
{
    // sort the jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second; });
    // first-> deadline , second-> profit
    int profit = jobs[0].second;
    int safedeadline = 2;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].first >= safedeadline)
        {
            profit += jobs[i].second;
            safedeadline++;
        }
    }
    return profit;
}
int main()
{
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20); // job1 with deadline 4 and profit 20
    jobs[1] = make_pair(1, 10); // job2 with deadline
    jobs[2] = make_pair(1, 40); // job3 with deadline 1 and profit 40
    jobs[3] = make_pair(1, 30); // job4 with deadline
    int result = maxProfit(jobs, n);
    cout << "Maximum profit: " << result << endl;
    return 0;
}