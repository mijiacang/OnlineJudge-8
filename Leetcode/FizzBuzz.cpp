/*************************************************************************
	> File Name: FizzBuzz.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Sunday, October 16, 2016 PM06:17:29 CST
 ************************************************************************/
/* 十分简单，不需要回顾此题。 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n);
};

vector<string> Solution::fizzBuzz(int n)
{
    vector<string> vecStr;
    for(int i = 1; i <= n; i++)
    {
        if(i % 15 == 0)
        {
            vecStr.push_back("FizzBuzz");
        }
        else if(i % 5 == 0)
        {
            vecStr.push_back("Buzz");
        }
        else if(i % 3 == 0)
        {
            vecStr.push_back("Fuzz");
        }
        else
        {
            vecStr.push_back(to_string(i));
        }
    }
    return vecStr;
}
