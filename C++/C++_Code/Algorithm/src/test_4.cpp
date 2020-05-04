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
    newNode->next = nullptr;

    if (*head == nullptr)
        *head = newNode;
    else
    {
        ListNode *p = *head;
        for (; p->next != nullptr; p = p->next)
            ;

        p->next = newNode;
    }
}

//对应剑指offer18，但是并不完整，如果涉及到头节点指针变化，则需要传入二级指针
// ListNode *deleteNode(ListNode *head, int val)
// {
//     ListNode *pHead = nullptr;

//     ListNode *p = head;
//     ListNode *q = head;  //用于记录要删除节点的上一个节点

//     for (; p != nullptr; p = p->next)
//     {
//         if (p->val == val)
//         {
//             q->next = p->next;
//             break;
//         }
//         q = p;
//     }
//     return head;
// }

void reverseList(ListNode *head)
{
    if (head == nullptr)
        cout << "The List is empty!" << endl;
    else
    {
        ListNode *p = head;

        for (; p != nullptr; p = p->next)
            cout << p->val << endl;
    }
}

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> vec;

        if (head == nullptr)
            cout << "The List is empty!" << endl;
        else
        {
            ListNode *p = head;

            for (; p != nullptr; p = p->next)
                vec.insert(vec.begin(), p->val);
        }
        return vec;
    }
};

int main(int argc, char **agrv)
{
    ListNode *head = nullptr;

    reverseList(head);

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    reverseList(head);

    Solution sol;

    vector<int> vec = sol.reversePrint(head);

    cout << "The result is:" << endl;
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
    ;

    return -1;
}

/*
总结：
 1.链表的头是一个指针，如果链表不为空就指向第一个节点，否则指向空；
 2.函数传参有两种形式：值传递与地址传递；如果想要改变传入参数，必须进行地址传递；对于指针而言，地址传递就是二级指针；当我们需要改变指针指向或者为指针分配空间时，需要传入指针的二级指针；
*/