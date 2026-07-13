class Solution {
public:
    void bitManipulation(int num, int i) 
    {
        i = i - 1;

        int bit = ((num & (1 << i)) != 0);
        cout << bit << " ";

        int num1 = (num | (1 << i));
        cout << num1 << " ";

        int num2 = (num & ~(1 << i));
        cout << num2;
    }
};