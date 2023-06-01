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
    void preOrder(TreeNode* root , vector<string> &nums, string temp)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) 
        {
            temp.push_back(root->val + '0');
            nums.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back((root->val) + '0');
        preOrder(root->left, nums,temp);
        preOrder(root->right, nums,temp);
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        vector<string> nums;
        string temp;
        preOrder(root, nums, temp);
        int ans = 0;
        for(auto i: nums) ans += stoi(i);
        return ans;
    }
};
