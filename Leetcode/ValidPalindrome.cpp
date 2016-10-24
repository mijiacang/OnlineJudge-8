/*************************************************************************
	> File Name: ValidPalindrome.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Monday, October 24, 2016 PM10:03:02 CST
 ************************************************************************/
// 这道题比较简单，但是一开始没有考虑一些特殊情况，比如空格及特殊字符或者空串怎样处理，面试时应该提出这些问题。
// 用 isdigit 和 isalpha 来判断一个 char 是否是数字或字母。
 
 
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s);
};
bool Solution::isPalindrome(string s)
{
    vector<char> vecChar;
    if(s.empty())
    {
        return true;
    }

    for(int i = 0; i < (int)s.length(); i++)
    {
        if((isdigit(s[i])) || (isalpha(s[i])))
        {
            vecChar.push_back(s[i]);
        }
    }
 
    int vecSize = vecChar.size();
    if(vecSize == 0)
    {
        return true;
    }

    int i = 0;
    int j = vecSize - i - 1;
    for(; i <= vecSize / 2; )
    {
        if(vecChar[i] != vecChar[j])
        {
            if((isdigit(vecChar[i])) || (isdigit(vecChar[j])))
            {
                return false;
            }
            else if((vecChar[i] - vecChar[j] != 32) && (vecChar[j] - vecChar[i] != 32))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;
}
