// stack implimentation using vector with class template
// template allows stack to store any datatype
#include <iostream>
#include <vector>
using namespace std;
// TEMPLATE STACK CLASS
template <typename T>
class Stack
{
    vector<T> vec; // internal container

public:
    // Push function
    void push(T val)
    {
        vec.push_back(val);
    }

    // Pop function
    void pop()
    {
        if (!vec.empty())
            vec.pop_back();
        else
            cout << "Stack underflow!\n";
    }

    // Top function
    T top()
    {
        if (!vec.empty())
            return vec.back(); // vector ka last element return karta hai
        throw runtime_error("Stack is empty!");
    }

    // Check empty
    bool empty()
    {
        return vec.empty();
    }

    // Size function
    int size()
    {
        return vec.size();
    }
};

int main()
{
    Stack<int> s; // integer stack

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top = " << s.top() << endl;
    s.pop();
    cout << "Top after pop = " << s.top() << endl;

    cout << "Size = " << s.size() << endl;

    // Using another datatype
    Stack<string> st;
    st.push("Sachin");
    st.push("Garg");

    cout << "String top = " << st.top() << endl;

    return 0;
}
