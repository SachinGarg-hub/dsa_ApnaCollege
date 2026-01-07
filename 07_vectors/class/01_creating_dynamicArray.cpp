#include <iostream>
using namespace std;
void func()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    int x = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    delete[] arr;
}
int main()
{
    func();
    return 0;
}