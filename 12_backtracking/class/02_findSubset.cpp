// find and print all subsets of a given string
/*
o size -> " " 1string
1 size ->"a" "b" "c"
2 size -> "ab" "bc""ca"
3 size -> "abc "
total subset =8 = 2^3

subset = 2^n

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printSubsets(string str, string subset)
{
    if (str.size() == 0)
    {
        cout << subset << "\n";
        return;
    }
    char ch = str[0];
    // yes choice
    printSubsets(str.substr(1, str.size() - 1), subset + ch);
    // no choice
    printSubsets(str.substr(1, str.size() - 1), subset);
}
int main()
{
    string str = "abc";
    string subset = " ";
    printSubsets(str, subset);
}