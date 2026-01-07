#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
void calculateStockSpan(int prices[], int n, int span[])
{
    stack<int> stk; // Stack to store indices of days

    for (int i = 0; i < n; i++)
    {
        // Pop elements from the stack while the current price is higher
        // than the price at the index stored at the top of the stack
        while (!stk.empty() && prices[i] >= prices[stk.top()])
        {
            stk.pop();
        }

        // If stack is empty, it means there is no higher price before
        if (stk.empty())
        {
            span[i] = i + 1; // Span is the entire length from day 0 to i
        }
        else
        {
            span[i] = i - stk.top(); // Span is the difference between current day and last higher price day
        }

        // Push this day's index onto the stack
        stk.push(i);
    }
}
int main()
{
    int prices[] = {100, 80, 60, 70, 60, 85, 100};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateStockSpan(prices, n, span);

    cout << "Stock Prices: ";
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }
    cout << endl;

    cout << "Stock Spans:  ";
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;

    return 0;
}