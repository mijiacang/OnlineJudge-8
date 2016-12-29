/*************************************************************************
	> File Name: AssignCookies.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Thu 29 Dec 2016 07:45:49 PM CST
 ************************************************************************/
// 这道题没意思。。。
#include <algorithm> // std::sort
#include <vector> 
#include <iostream>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s);
};

int Solution::findContentChildren(vector<int>& g, vector<int>& s)
{
  if((g.empty()) || (s.empty()))
  {
    return 0;
  }

  int num = 0;
  auto it_g = g.begin();
  auto it_s = s.begin();
  sort(it_g, g.end());
  sort(it_s, s.end());
  
  while(it_g != g.end())
  {
    if(it_s == s.end())
    {
      break;
    }
    
    if((*it_g) <= (*it_s))
    {
      ++num;
      ++it_g;
      ++it_s;
    }
    else
    {
      ++it_s;
    }
  }
  
  return num;
}
