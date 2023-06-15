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
    ListNode* reverse(ListNode* &head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr!= NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev =curr;
            curr = next;
        }
        return prev;
    }
    int getLen(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }   
    void reorderList(ListNode* head) {
        int len = getLen(head);
        int t = len;
        ListNode* tail = head, *prev = NULL, *temp = head, *newHead = NULL;
        if(len % 2 != 0) len++;
        len = len/2;
        while(len > 0)
        {
            prev = tail;
            tail = tail->next;
            len--;
        }
        prev->next = NULL;
        tail = reverse(tail);
        temp = head;
        ListNode* hNext = NULL, *tNext = NULL;
        while(temp != NULL || tail != NULL)
        {
            hNext = temp->next;
            if(tail)tNext = tail->next;
            temp->next = tail;
            temp = hNext;
            if(tail)tail->next = temp;
            tail = tNext;
        }
    }
};
