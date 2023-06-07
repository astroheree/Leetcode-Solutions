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
    void bfs(TreeNode* root, vector<vector<int>> &levelOrder)
    {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL)
            {
                levelOrder.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> levelOrder;
        bfs(root, levelOrder);
        for(int i = 0 ; i < levelOrder.size() ; i++)
        {
            int first = levelOrder[i][0];
            if(i%2 == 0)
            {  
                if(first % 2 == 0) return false;
                for(int j = 1 ; j < levelOrder[i].size() ; j++)
                {
                    if((levelOrder[i][j] % 2 == 0) || (first >= levelOrder[i][j])) return false; 
                    first = levelOrder[i][j];
                }
            }
            else
            {
                if(first % 2 != 0) return false;
                for(int j = 1 ; j < levelOrder[i].size() ; j++)
                {
                    if((levelOrder[i][j] % 2 != 0) || (first <= levelOrder[i][j])) return false;
                    first = levelOrder[i][j];
                }
            }
        }
        return true;
    }
};
