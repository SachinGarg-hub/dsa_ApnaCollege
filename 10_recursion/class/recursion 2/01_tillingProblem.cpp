#include <iostream>
using namespace std;
int tp(int n) // 2xn
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // vertical
    int ans1 = tp(n - 1); // 2xn-1
    // horizontal
    int ans2 = tp(n - 2); // 2xn-2
    return ans1 + ans2;
}
int main()
{
    cout << tp(4);
}