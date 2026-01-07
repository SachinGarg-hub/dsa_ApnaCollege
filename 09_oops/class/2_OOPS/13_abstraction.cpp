#include <iostream>
using namespace std;
// abstract class
class shape
{
public:
    virtual void draw() = 0;
};
class circle : public shape
{
public:
    void draw()
    {
        cout << "circle.." << endl;
    }
};
class square : public shape
{
public:
    void draw()
    {
        cout << "square.." << endl;
    }
};
int main()
{
    circle c1;
    c1.draw();
    square s1;
    s1.draw();
}