#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int areaHistogram(vector<int> &heights, int n)
{
    vector<int> nsl(n), nsr(n);
    stack<int> s;

    // Nearest Smaller to Left (NSL)
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = s.top();
        }

        s.push(i);
    }

    // Clear stack
    while (!s.empty())
    {
        s.pop();
    }

    // Nearest Smaller to Right (NSR)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            nsr[i] = n;
        }
        else
        {
            nsr[i] = s.top();
        }

        s.push(i);
    }

    // Calculate maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = nsr[i] - nsl[i] - 1;
        int area = heights[i] * width;

        if (area > maxArea)
        {
            maxArea = area;
        }
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();

    cout << "Maximum area in histogram: "
         << areaHistogram(heights, n);

    return 0;
}
