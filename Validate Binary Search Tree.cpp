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
    bool inOrder(TreeNode* root, long &last)
    {
        if(root == NULL) return true;
        if(last >= root->val) return false;

        bool left = inOrder(root->left,last);
        if(last >= root->val) return false;
        last = root->val;
        bool right = inOrder(root->right,last);
        
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        long last = -1e10;
        return inOrder(root, last);
    }
};
