#include <iostream>
#include <cstring>
using namespace std;
void toUppercase(char word[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            continue;
        }
        else
        {

            word[i] = ch - 'a' + 'A';
        }
    }
}
int main()
{
    char word[] = "ApPle";
    toUppercase(word, strlen(word));
    cout << word << endl;
}