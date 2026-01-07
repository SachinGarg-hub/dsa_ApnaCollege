#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    // decreasing
    cout << n << " ";
    print(n - 1);
    /* increasing order
      print(n - 1);
       cout << n << " ";
    */
}
int main()
{
    print(10);
}