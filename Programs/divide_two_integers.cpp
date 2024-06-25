#include<iostream>

int divide(int dividend, int divisor) 
{
    //INT_MIN = -2147483648
    //condition required for a testcase.
    if(dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    //labs = long long abs
    //get the positive values of dividend and divisor
    long long dvd = labs(dividend), dvs = labs(divisor), result = 0;
    //get the sign of the resultant 
    int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
    while(dvd >= dvs)
    {
        long long temp = dvs, mul = 1;
        while(temp << 1 <= dvd)
        {
            temp <<= 1;
            mul <<= 1;
        }
        dvd -= temp;
        result += mul;
    } 
    return sign*result; 
}

int main()
{
    int dividend = 0, divisor = 0;
    std::cout<<"Enter the dividend and divisor : "<<std::endl;
    std::cin>>dividend>>divisor;
    std::cout<<"Result after dividing : "<<divide(dividend, divisor);
    return 0;
}
