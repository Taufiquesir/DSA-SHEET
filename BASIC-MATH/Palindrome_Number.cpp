#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    int original_number = x;
    if (x < 0)
        return false;
    int rev = 0;
    while (x)
    {
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
        {
            return false;
        }
        rev = (rev * 10) + (x % 10);
        x /= 10;
    }
    return rev == original_number;
}
int main()
{
    int number;
    cout << "Enter the number\n";
    cin >> number;
    bool result = isPalindrome(number);
    cout << result << endl;
    return 0;
}