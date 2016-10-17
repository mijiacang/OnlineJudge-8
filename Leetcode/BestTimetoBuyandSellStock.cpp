/*************************************************************************
	> File Name: BestTimetoBuyandSellStock.cpp
	> Brief:
	> Author: liboyang
	> Mail: liboyang_mail@qq.com
	> Created Time: 星期一 10/17 23:13:17 2016
 ************************************************************************/
/* 超时，待修改。 */

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
            num = 0;
        }
    }
    for(int i = 0; i < num; i++)
    {
        prices.pop_back();
    }

    for(auto it = prices.begin(); it != prices.end() - 1; it++)
    {
        for(auto itt = it + 1; itt != prices.end(); itt++)
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
