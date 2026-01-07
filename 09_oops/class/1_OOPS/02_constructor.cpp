#include <iostream>
using namespace std;
class Car
{
    string name;
    string color;

public:
    Car(string nameVal, string colorVal)
    {
        name = nameVal;
        color = colorVal;
    }
    void start()
    {
        cout << "Car has started...\n";
    }
    void stop()
    {
        cout << "Car has stoped...\n";
    }
    // getter
    string getName()
    {
        return name;
    }
};
int main()
{
    Car c1("Maruti", "White");
    cout << c1.getName() << endl;
    return 0;
}