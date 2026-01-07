#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int> arr, vector<int> &ans)
{
    stack<int> s;
    int idx = arr.size() - 1;

    ans[idx] = -1; // last element has no next greater
    s.push(arr[idx]);

    for (idx = idx - 1; idx >= 0; idx--)
    {
        while (!s.empty() && s.top() <= arr[idx])
        {
            s.pop();
        }

        if (s.empty())
            ans[idx] = -1;
        else
            ans[idx] = s.top();

        s.push(arr[idx]);
    }
}

int main()
{
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans(arr.size());

    nextGreater(arr, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
