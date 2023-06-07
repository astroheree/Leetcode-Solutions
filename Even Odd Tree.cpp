/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool bfs(TreeNode* root)
    {
        if(root == NULL) return true;
        if(root->val % 2 == 0) return false;    
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag = false;
        int prev = 0;
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL)
            {
                if(flag) prev = 0;
                else prev = INT_MAX;
                if(!q.empty()) q.push(NULL);
                flag = !flag;
            }
            else
            {
                if((flag == false) && ((prev >= front->val) || (front->val % 2 == 0))) return false; 
                if((flag == true) && ((prev <= front->val) || (front -> val % 2 != 0))) return false;
                prev = front->val;
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        return bfs(root);
    }
};
