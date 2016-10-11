/*************************************************************************
	> File Name: ReverseBits.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Tuesday, October 11, 2016 PM08:03:41 CST
 ************************************************************************/
/* 很简单的一道题目，考察位操作。 */
 
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n);
};

uint32_t Solution::reverseBits(uint32_t n)
{
    uint32_t ret = 0;
    int flag = 0;
    int array[32] = {0};

    for(int i = 0; i < 32; i++)
    {
        flag = n & 1;
        array[i] = flag;
        n = n >> 1;
    }
    for(int i = 0; i < 32; i++)
    {
        ret = ret << 1;
        ret = ret + array[i];
    }

    return ret;
}

int main()
{
    Solution s;
    uint32_t a = 1;
    cout<<s.reverseBits(a)<<endl;
    return 0;
}
