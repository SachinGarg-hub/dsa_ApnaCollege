#include <iostream>
using namespace std;
int main()
{ /*
     char str[5] = {'s', 'a', 'c', 'k', 's'};
     cout << str[0] << endl;
     cout << str[1] << endl;
     cout << str[2] << endl;
     cout << str[3] << endl;
     cout << str[4] << endl;
     char arr[5] = {'c', 'o', 'd', 'e', '\O'};
     cout << arr << endl;
     return 0;
     /*
     "hello world" -> string literals
     this cant be change but char aaray cant be change


    char work[] = "code";
    char work[5] = "code";
    char work[] = {'c', 'o', 'd', 'e', '\O'};
    char work[50] = {'c', 'o', 'd', 'e', '\O'};
    */
    // input char array
    char word[30];
    cin >> word; // CIN IGNORES WHITESPACE
    cout << "your word was :" << word << endl;
    char sentence[50];
    cin.getline(sentence, 50, '.');
    cout << sentence << endl;
}