/*************************************************************************
    > File Name: SumOfLeftLeaves.cpp
    > Author: liboyang
    > Mail: 578072836@qq.com
    > Created Time: Saturday, October 08, 2016 PM08:26:25 CST
 ************************************************************************/
/* 缺点是可以用一个sum完成任务，却用了一个vector并进行了一次遍历。改进方式是在sumOfLeftLeaves函数里加一个sum，recurFuc函数里多加一个sum参数。*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root);
    void recurFuc(TreeNode* root);
private:
    vector<int> vecNum;
};

int Solution::sumOfLeftLeaves(TreeNode* root) {
    int ret = 0;
    vecNum.push_back(0);
    
    recurFuc(root);
    for(auto it = vecNum.begin(); it != vecNum.end(); it ++)
    {
        ret = ret + *it;
    }
    return ret;
}

void Solution::recurFuc(TreeNode* root) {
    if(NULL == root) {
        return;     
    }

    if((NULL != root->left) && (NULL == root->left->left) && (NULL == root->left->right)) {
        vecNum.push_back(root->left->val);
        recurFuc(root->right);
    }
    else {
        recurFuc(root->right);
        recurFuc(root->left);   
    }
}
