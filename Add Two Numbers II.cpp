/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr1 = l1, *curr2 = l2, *dH = dummyHead;
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL || carry != 0)
        {
            int val1 = 0, val2 = 0;
            if(curr1) val1 = curr1->val;
            if(curr2) val2 = curr2->val;
            int num = val1 + val2 + carry;
            int dig = num%10;
            carry = num/10;
            dH->next = new ListNode (dig);
            dH = dH->next;
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }
        dummyHead = dummyHead->next;
        dummyHead = reverse(dummyHead);
        return dummyHead;
    }
};
