// run time polymorphism
// function overriding
#include <iostream>
using namespace std;
class parent
{
public:
    void show()
    {
        cout << "parent class show.." << endl;
    }
    virtual void hello()
    {
        cout << "parent hello.." << endl;
    }
};
class child : public parent
{
public:
    void show()
    {
        cout << "Child class show.." << endl;
    }
    void hello()
    {
        cout << "Child hello.." << endl;
    }
};

int main()
{

    child c1;
    // c1.show();
    parent *ptr;
    ptr = &c1; // run time binding
    ptr->hello();
}