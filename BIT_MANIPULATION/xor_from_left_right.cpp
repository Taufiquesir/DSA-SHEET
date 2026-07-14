class Solution {
  public:
    int find_xor(int n)
    {
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else return n;
    }
    int findXOR(int l, int r) 
    {
        return find_xor(r)^find_xor(l-1);
    }
};