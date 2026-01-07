#include <iostream>
using namespace std;
int main()
{
    // adress of operator &
    //& gives the address of a vairable

    int a = 10;
    cout << &a << endl;
    /*what are pointers
    pointers are special variable that stores address of another
    variable
    */
    int *ptr = &a;
    cout << ptr << "=" << &a << endl;
    /*derefrence operator
     gets the valur of the varialble pointed by any pointer
    */
    cout << *(&a) << "=" << *ptr << endl;
    // null pointer
    // int *ptr1 = NULL;
    // cout << ptr1 << endl;
    // pq 1
    int x = 5, y = 10;
    int *ptr1 = &x;
    int *ptr2 = &y;
    ptr2 = ptr1;
    cout << ptr2 << endl;
}