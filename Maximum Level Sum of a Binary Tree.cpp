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
    // int bfs(TreeNode* root)
    // {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(NULL);
    //     int temp = 0,ans = -1e9,index = -1, count = 1;
    //     while(!q.empty())
    //     {
    //         TreeNode* front = q.front();
    //         q.pop();
            
    //         if(front == NULL)
    //         {
    //             if(temp > ans)
    //             {
    //                 ans = temp;
    //                 index = count;
    //             }
    //             count++;
    //             temp = 0;
    //             if(!q.empty()) q.push(NULL);
    //         }
    //         else
    //         {
    //             temp += front->val;
    //             if(front->left) q.push(front->left);
    //             if(front->right) q.push(front->right);
    //         }
    //     }
    //     return index;
    // }
    void dfs(TreeNode* root, vector<int> &m, int count)
    {
        if(root == NULL)
        {
            count--;
            return;
        }
        if(m[count] != -1e9)
        m[count] += root->val;
        else m[count] = root->val;
        dfs(root->left,m,count+1);
        dfs(root->right,m,count+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> v(1e5,-1e9);
        dfs(root,v,0);
        int sum = -1e9;
        for(int i = 0 ; i < 4;  i++) cout<<v[i]<<" ";
        cout<<endl;
        int index = 1,cnt = 1;
        for(auto i: v)
        {
            if(i>sum)
            {
                sum = i;
                index = cnt;
            }
            cnt++;
        }
        return index;
    }
};
