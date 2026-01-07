// print all binary string of size N without any consectuive 1s
/*
n=0 " "
n=1 "1""0"
n=2 "00" "10" "01"
*/
#include <iostream>
using namespace std;
void binaryString(int n, int lastplace, string ans)
{
    if (n == 0)
    {

        cout << ans << endl;
        return;
    }
    if (lastplace != 1)
    {
        binaryString(n - 1, 0, ans + '0');
        binaryString(n - 1, 1, ans + '1');
    }
    else
    {
        binaryString(n - 1, 0, ans + '0');
    }
}
int main()
{
    string ans = " ";
    binaryString(3, 0, ans);
}