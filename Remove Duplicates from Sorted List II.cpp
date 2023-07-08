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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(-101);
        newHead->next = head;
        ListNode* temp = head, *prev = newHead;
        while(temp != NULL)
        {
            if(temp->next != NULL && temp->val != temp->next->val) 
            {
                prev = temp;
                temp = temp->next;
            }
            else if(temp->next != NULL && temp->val == temp->next->val)
            {
                int value = temp->val;
                while(temp != NULL && temp->val == value) temp = temp->next;
                prev->next = temp;
            }
            else temp = temp->next;
        }
        return newHead->next;
    }
};
