// find 1st non-repeating letter in a stream of characters
// tc = O(n), sc = O(1)
#include <iostream>
#include <queue>
#include <string>
using namespace std;
void firstNonRepeatingLetter(const string &str)
{
    int charCount[26] = {0};
    queue<char> q;
    for (char ch : str)
    {
        charCount[ch - 'a']++;
        q.push(ch);
        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
            cout << -1 << " ";
    }
    cout << endl;
}
int main()
{
    string str = "aabccxb";
    firstNonRepeatingLetter(str);
    return 0;
}