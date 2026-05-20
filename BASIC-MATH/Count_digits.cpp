#include <iostream>
using namespace std;

int evenlyDivides(int n)
{
    // code here
    int count = 0;
    int original_number = n;
    while (n)
    {
        int d = n % 10;
        if (d != 0 && original_number % d == 0)
        {
            count++;
        }
        n /= 10;
    }
    return count;
}
int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    int result = evenlyDivides(number);
    cout << result << endl;
    return result;
}