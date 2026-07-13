# include<iostream>
using namespace std;

string TwosComplement(string binary)
{
    string onesComp = "";
    for (char bit : binary)
    {
        if (bit == '0')
            onesComp += '1';
        else if (bit == '1')
            onesComp += '0';
        else
            return "Invalid binary number";
    }

    // Add 1 to the one's complement
    int carry = 1;
    string twosComp = "";
    for (int i = onesComp.length() - 1; i >= 0; i--)
    {
        if (onesComp[i] == '1' && carry == 1)
        {
            twosComp = '0' + twosComp;
        }
        else if (onesComp[i] == '0' && carry == 1)
        {
            twosComp = '1' + twosComp;
            carry = 0;
        }
        else
        {
            twosComp = onesComp[i] + twosComp;
        }
    }

    if (carry == 1)
    {
        twosComp = '1' + twosComp;
    }

    return twosComp;
}

int main()
{
    string binary;
    cout << "Enter the Binary number:";
    cin >> binary;  
    cout << "Twos complement of " << binary << " is " << TwosComplement(binary) << "\n";
}