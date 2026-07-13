
    #include<iostream>
    using namespace std;

    void bitManipulation(int number,int k) 
    {
        k = k - 1;
        int num1 = (number ^ (1 << k));
        cout << num1 << " ";
    }
int main()
{
    int number,bit_number;
    cout << "Enter the Binary number:";
    cin >> number>>bit_number;
    bitManipulation(number,bit_number);
}