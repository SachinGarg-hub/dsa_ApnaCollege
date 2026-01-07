// static variable
#include <iostream>
using namespace std;

class Demo
{
public:
    // Static data member
    static int count;

    // Constructor
    Demo()
    {
        count++; // har object banne par count increase hoga
    }

    // Static member function
    static void showCount()
    {
        cout << "Total objects created: " << count << endl;
    }
};

// Static data member ko class ke bahar define karna zaroori hota hai
int Demo::count = 0;

// Static function example (non-member)
void staticFunctionExample()
{
    static int num = 0; // static variable function ke andar
    num++;
    cout << "Function called " << num << " times" << endl;
}

int main()
{
    Demo d1, d2, d3;   // 3 objects
    Demo::showCount(); // static member function ko class name se call kiya

    cout << endl;

    // static function example
    staticFunctionExample(); // 1st call
    staticFunctionExample(); // 2nd call
    staticFunctionExample(); // 3rd call

    return 0;
}
