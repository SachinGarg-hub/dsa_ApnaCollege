#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec1;
    vector<int> vec2 = {1, 2, 3, 4};
    vector<int> vec3(5, -1); // all index pe -1 hoga
    cout << vec3.size();
    // implementation of vector in memory
    cout << "Size : " << vec2.size() << endl;
    cout << "Capacity : " << vec2.capacity() << endl;
    vec2.push_back(5);
    cout << "Size : " << vec2.size() << endl;
    cout << "Capacity : " << vec2.capacity() << endl;
}