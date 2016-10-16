/*************************************************************************
	> File Name: HappyNumber.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Thursday, October 13, 2016 PM08:30:54 CST
 ************************************************************************/
/* 这个题没什么意思，就是说肯定会循环到结果为个位数，个位数里面只有 1 和 7 是 HappyNumber ，其他的都不是。 */
 
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n);
    int redoFuc(int n); 
};

bool Solution::isHappy(int n)
{
    while(n > 9)
    {
        n = redoFuc(n);
    }

    if((n == 1) || (n == 7))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Solution::redoFuc(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n = 1;
    Solution s;
    cout<<s.isHappy(n)<<endl;
    return 0;
}
