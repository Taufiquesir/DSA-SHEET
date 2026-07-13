#include<iostream>
using namespace std;

int binaryToDecimal(string n)
{
    int len = n.length();
    int decimal = 0;
    int base = 1;    
    for (int i = len - 1; i >= 0; i--)
    {
        if (n[i] == '1')
            decimal += base;
        base = base * 2;
    }
    return decimal;
}

int main()
{
    string binary;
    cout << "Enter the Binary number:";
    cin >> binary;
    cout<<"Decimal equivalent of "<< binary <<"  is  "<<binaryToDecimal(binary)<<"\n";
}