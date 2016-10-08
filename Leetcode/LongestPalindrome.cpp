/*************************************************************************
	> File Name: LongestPalindrome.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Saturday, October 08, 2016 PM09:29:57 CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string &s);
};

int Solution::longestPalindrome(string &s) {
    vector<int> vecCharNum(52,0);
    int odd = 0;
    int ret = 0;
    int size = s.length();
    
    for(int i = 0; i < size; i ++)
    {
        if((int)s[i] < 'a') {
            vecCharNum[(int)(s[i] - 'A' + 26)] ++;
        }
        else {
            vecCharNum[(int)(s[i] - 'a')] ++;
        }
    }
    for(auto it = vecCharNum.begin(); it != vecCharNum.end(); it ++)
    {
        if(*it % 2 == 0) {
            ret = ret + *it;
        }
        else if(*it != 0) {
	    ret = ret + ((*it) - 1);
            odd = 1;
        }
	else {}
    }

    return ret + odd;
}
