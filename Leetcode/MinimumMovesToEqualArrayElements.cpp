/*************************************************************************
	> File Name: MinimumMovesToEqualArrayElements.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: 三  1/ 4 20:39:35 2017
 ************************************************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
        {
            return 0;
        }
        
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        auto it = nums.rbegin();
        int temp_back = *it;
        
        int temp_front = 0;
        for(it++; it != nums.rend(); it++)
        {
            temp_front = *it;
            sum = sum + (temp_back - temp_front) * (it - nums.rbegin());
            temp_back = temp_front;
        }
        return sum;
    }
};
