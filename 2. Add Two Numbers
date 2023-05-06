class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* newHead = new ListNode(-1);
        ListNode* curr2 = newHead;
        int carry = 0;
        while(temp1 != NULL || temp2!= NULL)
        {
            int d1=0,d2=0;
            if(temp1)
            {
                d1 = temp1->val;
            }
            if(temp2)
            {
                d2 = temp2->val;
            }
            int dig = d1 + d2 + carry;
            carry = dig/10;
            dig = dig%10;
            curr2->next = new ListNode(dig);
            curr2 = curr2->next;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry!=0)
        curr2->next = new ListNode(carry);
        return newHead->next;
    }
};
