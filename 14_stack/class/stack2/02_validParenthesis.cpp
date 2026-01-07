#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValidParenthesis(const string &s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValidParenthesis(s))
    {
        cout << "The parentheses are valid." << endl;
    }
    else
    {
        cout << "The parentheses are not valid." << endl;
    }

    return 0;
}