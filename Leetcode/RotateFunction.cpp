/*************************************************************************
	> File Name: RotateFunction.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Wednesday, October 12, 2016 PM08:09:49 CST
 ************************************************************************/
/* 解题思路太直接，没有经过思考，导致超时。 */
 
#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
using namespace std;


/* 最好的算法，但是有一些高中数学的解题思想
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size(), sum = 0, tmp1 = 0, tmp2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            tmp1 += i * A[i];
        }
        ans = tmp1;
        for(int i = 1; i < n; i++){
            tmp2 = sum + tmp1 - n * A[n - i];
            ans = max(ans, tmp2);
            tmp1 = tmp2;
        }
        return ans;
    }
};
*/


class Solution {
public:
    int maxRotateFunction(vector<int>& A);
};

int Solution::maxRotateFunction(vector<int>& A)
{
   // 把数据放到双向队列里面
   deque<int> dequeInt;
   if(A.empty())
   {
       return 0;
   }
   for(auto it = A.begin(); it != A.end(); it++)
   {
       dequeInt.push_back(*it); 
   }

   // 计算结果集
   int dequeSize = dequeInt.size();
   vector<int> vecMax(dequeSize,0);
   for(int i = 0; i < dequeSize; i++)
   {
       int j = 0;
       for(auto it = dequeInt.begin(); it != dequeInt.end(); it++)
       {
           vecMax[i] = vecMax[i] + j * (*it);
           j++; 
       }
       
       // cout<<vecMax[i]<<endl;
       dequeInt.push_back(dequeInt[0]);
       dequeInt.pop_front();
   }

   // 找出结果集中的最大值并返回
   int ret = INT_MIN;
   for(auto it = vecMax.begin(); it != vecMax.end(); it ++)
   {
       if(*it > ret)
       {
           ret = *it;
       }
   }
   return ret;
}

int main()
{
    vector<int> A = {4,3,2,6};
    Solution s;
    cout<<s.maxRotateFunction(A)<<endl;
    return 0;
}
