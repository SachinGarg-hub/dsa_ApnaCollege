#include <iostream>
using namespace std;

// Class A ke private data ko Class B access karegi
class A
{
private:
    int secret = 123; // private member

    // Class B ko friend banaya gaya hai
    friend class B;
};

class B
{
public:
    void showSecret(A obj)
    {
        cout << "Secret value of A is: " << obj.secret << endl;
    }
};

int main()
{
    A objA;
    B objB;

    objB.showSecret(objA); // B class A ke private data ko access kar rahi hai
    return 0;
}
