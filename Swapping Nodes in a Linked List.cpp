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
        int len = 0;
        while(head != NULL)
        {
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int len = getLen(temp);
        int firstNodeIndex = k, lastNodeIndex = len-k+1;
        if(k>len/2)
        {
            firstNodeIndex = len-k+1;
            lastNodeIndex = k;
        }
        ListNode* firstNodePointer = NULL;
        ListNode* lastNodePointer = NULL;
        while(temp != NULL)
        {
            if(firstNodeIndex == 1)  firstNodePointer = temp;
            if(lastNodeIndex == 1) lastNodePointer = temp;
            temp = temp->next;
            firstNodeIndex--;
            lastNodeIndex--;
        }
        int firstNodeData = firstNodePointer->val;
        firstNodePointer->val = lastNodePointer->val;
        lastNodePointer->val = firstNodeData;
        return head;

    }
};
