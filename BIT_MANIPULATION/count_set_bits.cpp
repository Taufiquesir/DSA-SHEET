int count_no_of_1(int n)
{
    int count=0;
    while(n>0)
    {
        count+=(n & 1);     //find odd number and rem for odd is 1
        n=n>>1;        //right shift by one means divide by 1.
    }
    return count;
}
    