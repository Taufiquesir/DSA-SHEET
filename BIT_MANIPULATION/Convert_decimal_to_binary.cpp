#include <iostream>
using namespace std;
string desimalToBinary(int n)
{
    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary;
}

int main()
{
    int number;
    cout << "Enter the Decimal number:";
    cin >> number;
    cout << "Binary equivalent of " << number << " is " << desimalToBinary(number)<<"\n";
}