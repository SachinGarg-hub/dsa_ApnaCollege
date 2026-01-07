#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool duplicateParenthesis(const string &s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == ')')
        {
            if (st.top() == '(')
            {
                return true; // Found duplicate
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop(); // Pop the opening parenthesis
            }
        }
        else
        {
            st.push(ch);
        }
    }
    return false; // No duplicates found
}
int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (duplicateParenthesis(s))
    {
        cout << "The string contains duplicate parentheses." << endl;
    }
    else
    {
        cout << "The string does not contain duplicate parentheses." << endl;
    }

    return 0;
}