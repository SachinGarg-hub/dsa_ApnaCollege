// compile time polymorphism

#include <iostream>
using namespace std;
// fnx overloading
class Print
{
public:
    void show(int x)
    {
        cout << "int : " << x << endl;
    }
    void show(string a)
    {
        cout << "string : " << a << endl;
    }
};
// operator overloading
class Complex
{
    int real;
    int img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }
    void showNum()
    {
        cout << real << " + " << img << "i " << endl;
    }
    // operator overloading
    void operator+(Complex &c2)
    {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal, resImg);
        cout << "res= ";
        c3.showNum();
    }
};
int main()
{
    /* Print p1;
     p1.show(10);
     p1.show("abc");
 */
    Complex c1(4, 3);
    Complex c2(8, 7);
    c1.showNum();
    c2.showNum();
    c1 + c2;
}