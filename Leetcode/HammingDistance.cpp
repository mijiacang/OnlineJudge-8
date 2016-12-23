/*************************************************************************
	> File Name: HammingDistance.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Tue 20 Dec 2016 08:28:42 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int m = 0x00000001;
        int count = 0;
        for(int i = 0; i < 32; ++i)
        {
            count += ((x & m) != (y & m));
            x >>= 1; y >>= 1;
        }   
        
        return count;
    }
};
