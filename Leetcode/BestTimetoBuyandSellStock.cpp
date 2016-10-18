/*************************************************************************
	> File Name: BestTimetoBuyandSellStock.cpp
	> Brief:
	> Author: liboyang
	> Mail: liboyang_mail@qq.com
	> Created Time: 星期一 10/17 23:13:17 2016
 ************************************************************************/
/* 一开始超时，后来做了针对测试用例的修改，把首段和尾段的递减数列忽略。虽然通过了测试，但时间复杂度并没有变。 */
/* 整个思路就错了，完全没必要两次遍历，一次就可以。以后要先想好算法在开始写代码！*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices);
};

/* 修改前的代码，时间复杂度是O(n*n)。 */
/*
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
*/

/* 修改后的代码,时间复杂度是O(n)。 */
int Solution::maxProfit(vector<int>& prices)
{
    int minPrice = INT_MAX; // 遍历到的位置之前的最小价值
    int maxPro = 0; // 遍历到的位置之前的最大收益

    for(auto it = prices.begin(); it != prices.end(); it++)
    {
        if(*it < minPrice)
        {
            minPrice = *it;
        }
        else
        {
            maxPro = max(maxPro, (*it - minPrice));
        }
    }
    return maxPro;
}
