class Solution {
public:
bool check_palindrome(int left,int right,string& s)
    {
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right]))right--;
        if(left>=right) return true;
        if(tolower(s[left]) != tolower(s[right])) return false;
        return check_palindrome(left+1,right-1,s);
    }
    bool isPalindrome(string s) 
    {
        return check_palindrome(0,s.size()-1,s);        
    }
};