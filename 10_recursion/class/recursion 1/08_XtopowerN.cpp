// wap to print x to power of n
#include <iostream>
using namespace std;
/*
O(n)
int power(int x, int n) {
    // Base case
    if (n == 0)
        return 1;

    // Recursive case
    return x * power(x, n - 1);
}
*/
// Function to calculate x^n in O(log n)
int power(int x, int n)
{
    // Base case
    if (n == 0)
        return 1;

    // Recursive call for half power
    int half = power(x, n / 2);

    // If n is even
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half; // If n is odd
}

int main()
{
    int x, n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << x << " raised to power " << n << " is: " << power(x, n) << endl;
    return 0;
}
