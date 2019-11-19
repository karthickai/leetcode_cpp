/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyRoot = new ListNode(0);
        auto *ptr = dummyRoot;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            ptr->next = new ListNode(carry);
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }
};