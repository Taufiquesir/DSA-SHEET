
    #include<iostream>
    using namespace std;

    void Remove_lat_set_bit(int number) 

    {
        cout << (number & (number - 1)) << " " ;
    }
int main()
{
    int number;
    cout << "Enter the Binary number:";
    cin >> number;
    Remove_lat_set_bit(number);
}