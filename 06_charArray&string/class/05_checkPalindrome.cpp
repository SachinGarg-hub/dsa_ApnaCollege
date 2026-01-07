#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char word[], int n)
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        if (word[st] != word[end])
        {
            cout << "Not a palindrome" << endl;
            return false;
            st++;
            end--;
        }
        cout << "valid palindrome" << endl;
        return true;
    }
}
int main()
{
    char word[] = "racecar";
    int n = strlen(word);
    isPalindrome(word, n);
}