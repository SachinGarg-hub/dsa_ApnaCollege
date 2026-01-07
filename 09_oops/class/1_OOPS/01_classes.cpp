#include <iostream>
using namespace std;
class Student
{
    // properties
    string name;
    float cgpa;

public: // access modifier
    // method
    void getpercentage()
    {
        cout << (cgpa * 10) << "% ";
    }
    // setter
    void setName(string nameval)
    {
        name = nameval;
    }
    void setCgpa(float cgpaval)
    {
        cgpa = cgpaval;
    }
    // getter
    string getname()
    {
        return name;
    }
    float getCgpa()
    {
        return cgpa;
    }
};
int main()
{
    Student s1; // object
    s1.setName("Sachin");
    s1.setCgpa(9);
    cout << s1.getname() << endl;
    cout << s1.getCgpa() << endl;
    return 0;
}    