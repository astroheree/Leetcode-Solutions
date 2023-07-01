class Solution {
private:
    void solve(int ind, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(ind > n) return;
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        solve(ind+1,n,k,temp,ans);

        temp.push_back(ind + 1);
        solve(ind+1,n,k,temp,ans);
        temp.pop_back();

        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,n,k,temp,ans);
        return ans;
    }
};
