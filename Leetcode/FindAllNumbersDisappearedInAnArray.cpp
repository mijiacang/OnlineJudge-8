/*************************************************************************
	> File Name: FindAllNumbersDisappearedInAnArray.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Tue 20 Dec 2016 08:55:20 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        size_t size = nums.size();
        bitset<100000> bitVec = 0;
        for(int i = 0; i < size; i++)
        {
            bitVec[nums[i]] = 1;
        }
        
        vector<int> retVec;
        for(int i = 1; i <= size; i++)
        {
            if(bitVec[i] == 0)
            {
                retVec.push_back(i);
            }
        }
        return retVec;
    }
};
