#include <iostream>
using namespace std;

int count = 1;
void printNos(int n)
{
    if (count > n)
        return;
    cout << count++ << " ";
    printNos(n);
}
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    printNos(number);
    return 0;
}