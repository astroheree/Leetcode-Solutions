/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == head) return head;
        ListNode* slow = head, *fast = head;
        while(fast != NULL && slow != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!= NULL) fast = fast->next;
            if(slow == fast) break;
        }
        if(fast == NULL) return nullptr;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};
