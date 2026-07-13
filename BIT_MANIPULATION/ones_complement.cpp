#include<iostream>
using namespace std;

string onesComplement(string binary)
{
    string result = "";
    for (char bit : binary)
    {
        if (bit == '0')
            result += '1';
        else if (bit == '1')
            result += '0';
        else
            return "Invalid binary number";
    }
    return result;
}

int main()
{
    string binary;
    cout << "Enter the Binary number:";
    cin >> binary;
    cout << "Ones complement of " << binary << " is " << onesComplement(binary)<<"\n";
}