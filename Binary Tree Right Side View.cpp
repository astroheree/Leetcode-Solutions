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
private:
    void bfs(TreeNode* root, vector<int> &ans, int lev)
    {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL)
            {
                lev++;
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                if(lev-1 >= ans.size())
                {
                    ans.push_back(1);
                }
                ans[lev-1] = front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return;
    }       
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        bfs(root,ans,1);
        return ans;
    }
};
