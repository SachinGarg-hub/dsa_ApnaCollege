#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
void reverseString(char str[])
{
    stack<char> stk;
    int n = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++)
    {
        stk.push(str[i]);
    }

    // Pop characters from the stack and put them back into the string
    for (int i = 0; i < n; i++)
    {
        str[i] = stk.top();
        stk.pop();
    }
}
int main()
{
    char str[] = "Hello, World!";
    cout << ("Original String:") << str << endl;

    reverseString(str);

    cout << ("Reversed String: ") << str << endl;
    return 0;
}
