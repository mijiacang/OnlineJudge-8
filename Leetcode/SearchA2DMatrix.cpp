/*************************************************************************
	> File Name: SearchA2DMatrix.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Fri 23 Dec 2016 03:31:55 PM CST
 ************************************************************************/

// 把矩阵当成一个链表，二分查找
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target);
    int FindInMatrixByListNo(vector<vector<int> >& matrix, int col_num, int list_no);
    bool RecursionFuc(vector<vector<int> >& matrix, int start, int end, int col_num, int target);
};

int Solution::FindInMatrixByListNo(vector<vector<int> >& matrix, int col_num, int list_no)
{
  int i = list_no / col_num;
  int j = list_no - (i * col_num);
  return matrix[i][j];
}

bool Solution::RecursionFuc(vector<vector<int> >& matrix, int start, int end, int col_num, int target)
{
  if(start > end)
  {
    return false;
  }
  
  int mid_pos = (start + end) / 2;
  int mid_num = FindInMatrixByListNo(matrix, col_num, mid_pos);
  
  if(mid_num == target)
  {
    return true;
  }
  else if(mid_num > target)
  {
    end = mid_pos - 1;
    return RecursionFuc(matrix, start, end, col_num, target);
  }
  else
  {
    start = mid_pos + 1;
    return RecursionFuc(matrix, start, end, col_num, target);
  }
}

bool Solution::searchMatrix(vector<vector<int> >& matrix, int target)
{
  int row_num = matrix.size();
  if(((int)row_num == 0))
  {
    return false;
  }
  int col_num = (matrix.begin())->size();
  if(((int)col_num == 0))
  {
    return false;
  }
  
  if(target < matrix[0][0])
  {
    return false;
  }
  if(target > matrix[row_num - 1][col_num - 1])
  {
    return false;
  }
  
  int start = 0;
  int end = row_num * col_num;

  return RecursionFuc(matrix, start, end, col_num, target);
}

int main()
{
  vector<int> v1;
  for(int i = 0; i <= 4; i++)
  {
    v1.push_back(i);
  }

  vector<int> v2;
  for(int i = 6; i <= 10; i++)
  {
    v2.push_back(i);
  }

  vector<vector<int> > matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);

  Solution s;
  if(s.searchMatrix(matrix,11) == true)
  {
    cout<<"find le"<<endl;
  }
  else
  {
    cout<<"no find"<<endl;
  }

  return 0;
}
