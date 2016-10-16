/*************************************************************************
	> File Name: RemoveDuplicatesfromSortedList.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Sunday, October 16, 2016 PM06:32:06 CST
 ************************************************************************/
/* 很简单，就是一道单向有序链表删除节点的问题，遍历删除即可。 */
 
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head)
{
    if(head == NULL)
    {
        return head;
    }
    
    int CurNum = head->val;
    ListNode* curNode = head;
    ListNode* nextNode = curNode->next;
    
    while(nextNode != NULL)
    {
        if(nextNode->val != CurNum)
        {
            CurNum = nextNode->val;
            curNode = curNode->next;
            nextNode = curNode->next;
        }
        else
        {
            nextNode = nextNode->next;
            free(curNode->next);
            curNode->next = nextNode;
        }
    }
    
    return head;
}
