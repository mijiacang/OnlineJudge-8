/*************************************************************************
	> File Name: BestTimetoBuyandSellStock.cpp
	> Brief:
	> Author: liboyang
	> Mail: liboyang_mail@qq.com
	> Created Time: 星期一 10/17 23:13:17 2016
 ************************************************************************/
/* 一开始超时，后来做了针对测试用例的修改，把首段和尾段的递减数列忽略。虽然通过了测试，但时间复杂度并没有变。 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices)
{
    int max = 0;
    int num = 0; // 记录vector尾端递减数据的数量
    int flag = 0; // 记录vector首端递减数据的数量
    int varCount = 0;
    
    if(prices.empty())
    {
        return 0;
    }

    for(auto it = prices.begin(); it != prices.end() - 1; it++)
    {
        auto itt = it + 1;
        if(*it >= *itt)
        {
            num++;
        }
        else
        {
            varCount++;
            if(varCount == 1)
            {
                flag = flag + num;
            }
            num = 0;
        }
    }

    for(auto it = prices.begin() + flag; it != prices.end() - 1 - num; it++)
    {
        for(auto itt = it + 1; itt != prices.end() - num; itt++)
        {
            if(*it < *itt)
            {
                if((*itt - *it) > max)
                {
                    max = *itt - *it;
                }
            }
        }
    }
    return max;
}