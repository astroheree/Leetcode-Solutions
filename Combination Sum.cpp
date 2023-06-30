class Solution {
private:
    void solve(int ind, vector<int> &candidates, int n, int t, vector<vector<int>> &ans, vector<int> &temp)
    {
        if(t == 0) 
        {
            ans.push_back(temp);
            return;
        }
        if(ind == n) return;
        solve(ind+1,candidates, n,t, ans, temp);
        if(candidates[ind] <= t)
        {
            temp.push_back(candidates[ind]);
            solve(ind,candidates, n,t-candidates[ind],ans,temp);
            temp.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(0,candidates,n,target, ans, temp);
        return ans;
    }
};
