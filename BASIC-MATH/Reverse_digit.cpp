#include <iostream>
using namespace std;
int reverseDigits(int n)
{
    // Code here
    int rev = 0;
    while (n)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
int main()
{
    int number;
    cout << "Enter the number\n";
    cin >> number;
    int result = reverseDigits(number);
    cout << result << endl;
    return result;
}