#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
public:
    int id;
    int deadline;
    int profit;

    Job(int i, int d, int p)
    {
        id = i;
        deadline = d;
        profit = p;
    }
};

int maxProfit(vector<pair<int, int>> pairs)
{
    int n = pairs.size();
    vector<Job> jobList;

    for (int i = 0; i < n; i++)
    {
        jobList.emplace_back(i + 1, pairs[i].first, pairs[i].second);
    }

    // Sort by profit (descending)
    sort(jobList.begin(), jobList.end(),
         [](Job &a, Job &b)
         {
             return a.profit > b.profit;
         });

    int maxDeadline = 0;
    for (auto j : jobList)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;

    cout << "Selected jobs: ";

    for (auto job : jobList)
    {
        for (int d = job.deadline; d > 0; d--)
        {
            if (slot[d] == -1)
            {
                slot[d] = job.id;
                totalProfit += job.profit;
                cout << "Job" << job.id << " ";
                break;
            }
        }
    }

    cout << endl;
    return totalProfit;
}

int main()
{
    vector<pair<int, int>> jobs;
    jobs.push_back({4, 20});
    jobs.push_back({1, 10});
    jobs.push_back({1, 40});
    jobs.push_back({1, 30});

    int result = maxProfit(jobs);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
