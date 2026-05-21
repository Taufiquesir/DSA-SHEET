#include <iostream>
using namespace std;

void Print_name(string name, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << name << endl;
    Print_name(name, n - 1);
}

int main()
{
    string name;
    int n;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the number of times you want to print your name: ";
    cin >> n;
    Print_name(name, n);
    return 0;
}
