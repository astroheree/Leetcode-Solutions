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
private:
    int getLen(ListNode* head)
    {
        int n = 0;
        while(head != NULL)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head, *next = NULL;
        while(curr!= NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLen(head);
        if(head == NULL || head->next == NULL || k == 0) return head;
        if(k % len == 0) return head;
        k = k % len;
        head = reverse(head);
        ListNode* prev = NULL, *curr = head;
        while(k--)
        {
            prev = curr;
            curr = curr->next;
        }
        if(prev) prev->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = reverse(curr);
        return newHead;
    }
};
