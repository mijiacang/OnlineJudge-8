/*************************************************************************
	> File Name: BinaryWatch.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Monday, October 10, 2016 PM07:59:40 CST
 ************************************************************************/
/* 自己没想出辙，照着别人的抄了一份，学习借鉴！ */

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h < 12; ++h)
            for(int m = 0; m < 60; ++m)
                if((int)(bitset<10>((h<<6)+m).count()) == num)
                {
                    string str = to_string(h) + ":";
                    str += (m < 10) ? ("0" + to_string(m)) : to_string(m);
                    res.push_back(str);
                }
        return res;
    }
};
