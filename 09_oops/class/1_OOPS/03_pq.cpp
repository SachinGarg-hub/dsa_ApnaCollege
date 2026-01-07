/* Create a User class with properties:
id (private), username(public) & password (private).
Its id should be initialized in a parameterised constructor.
It should have a Getter & Setter for password.*/
#include <iostream>
using namespace std;
class user
{
private:
    int id;
    string password;

public:
    string username;
    user(int id)
    {
        this->id = id;
    }
    // getter
    string getPassword()
    {
        return password;
    }
    // setter
    void setPassword(string password)
    {
        this->password = password;
    }
};
int main()
{
    user u1(101);
    u1.username = "SG";
    u1.setPassword("abc");
    cout << "username=" << u1.username << endl;
    cout << "passowrd=" << u1.getPassword() << endl;
}