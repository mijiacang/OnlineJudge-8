/*************************************************************************
	> File Name: AddBinary.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Tuesday, October 11, 2016 PM08:37:05 CST
 ************************************************************************/
/* 比较简单 */
 
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b);
};

string Solution::addBinary(string a, string b)
{
    int maxLen = 0;
    int minLen = 0;
    string* maxStrPtr = NULL;
    string* minStrPtr = NULL;

    if(a.length() > b.length())
    {
        maxLen = a.length();
        maxStrPtr = &a;
        minLen = b.length();
        minStrPtr = &b;
    }
    else
    {
        maxLen = b.length();
        maxStrPtr = &b;
        minLen = a.length();
        minStrPtr = &a;
    }

    string retStr(maxLen,'0');
    int carry = 0;
    
    for(int i = minLen; i < maxLen; i++)
    {
        *minStrPtr = "0" + *minStrPtr;
    }
    
    for(int i = 0; i < maxLen; i++)
    {
        int sum = ((*maxStrPtr)[maxLen - 1 - i] - '0') + ((*minStrPtr)[maxLen - 1 - i]  - '0') + carry;        
        if(sum == 2)
        {
            sum = 0;
            carry = 1;
        }
        else if(sum == 3)
        {   
            sum = 1;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        retStr[maxLen - 1 - i] = (char)('0' + sum);
    }
    
    if(carry == 1)
    {
        retStr = "1" + retStr;
    }
    return retStr;
}

int main()
{
    string a = "11";
    string b = "11";
    Solution s;
    cout<<s.addBinary(a,b);
    return 0;
}
