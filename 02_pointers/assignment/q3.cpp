#include <iostream>
using namespace std;
int main()
{
    int a = 32;
    int *ptr = &a;

    char ch = 'A';  //'A' ascii value =65
    char &cho = ch; // cho refrence of ch
    cho += a;       // ch =ch+a=65+32=91=>a ch=a
    *ptr += ch;     //*ptr =a a=a+ch=32+97=129
    cout << a << "," << ch << endl;
}