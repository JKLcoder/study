/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/

#include <iostream>
#include <vector>
#include <malloc.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void append(ListNode **head, int target)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == nullptr)
    {
        cout << "malloc failed!" << endl;
        return;
    }

    newNode->val = target;

    if ((*head)->next == nullptr)
        (*head)->next = newNode;
    else
    {
        ListNode *p = *head;
        ListNode *q = nullptr;
        for (; p->next != nullptr;)
        {
            q = p;
            p = p->next->next;
        }
        q->next = newNode;
    }
}

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> vec;

        ListNode *p = head;

        for (; p->next != nullptr;)
        {
            cout << p->val << endl;
            p = p->next->next;
        }
    }
};

int main(int argc, char **agrv)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = nullptr;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    Solution sol;
    // sol.reversePrint(head);

    return -1;
}