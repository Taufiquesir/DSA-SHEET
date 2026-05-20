#include<bits/stdc++.h>
using namespace std;
int isPrime(int n)
{
    int count=0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) 
        {
            count++;
            if(n/i!=i)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    if(number==1) return 0;
    int result = isPrime(number);
    cout << result << endl;
    return result;
}