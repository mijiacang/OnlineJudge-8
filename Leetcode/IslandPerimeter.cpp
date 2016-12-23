/*************************************************************************
	> File Name: IslandPerimeter.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Wed 21 Dec 2016 03:33:42 PM CST
 ************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid);
};

int Solution::islandPerimeter(vector<vector<int>>& grid) {
  int count=0, repeat=0;
  for(int i=0;i<grid.size();i++)
  {
    for(int j=0; j<grid[i].size();j++)
      {
        if(grid[i][j]==1)
        {
          count ++;
          if(i!=0 && grid[i-1][j] == 1) repeat++;
          if(j!=0 && grid[i][j-1] == 1) repeat++;
        }
      }
  }
  return 4*count-repeat*2;
}