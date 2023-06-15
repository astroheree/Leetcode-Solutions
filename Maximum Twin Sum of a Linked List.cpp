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
    int getLen(ListNode* head)
    {
        int count =0;
        while(head != NULL) 
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr!= NULL)  
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int len = getLen(head);
        ListNode* temp = head, *prev = NULL;
        len = len/2;
        while(len--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = reverse(temp);
        temp = head;
        prev= prev->next;
        int ans = INT_MIN;
        while(prev != NULL)
        {
            int sum = temp->val + prev->val;
            ans = max(sum,ans);
            temp = temp->next;
            prev = prev->next;
        }
        return ans;

    }
};
