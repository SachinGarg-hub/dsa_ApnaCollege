#include <iostream>
#include <cstring>
using namespace std;
void toReverse(char word[], int n)
{
    int st = 0;
    int end = n - 1;
    while (st < end)
    {
        swap(word[st], word[end]);
        st++;
        end--;
    }
}
int main()
{
    char word[] = "code";
    toReverse(word, strlen(word));
    cout << "reverse = " << word << endl;
}