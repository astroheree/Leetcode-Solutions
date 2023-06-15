class Solution {
public:
    long long solve(int ind, vector<vector<int> > &questions, int n, vector<long long> &dp)
    {
        if(ind >= n) return 0;
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        long long add = questions[ind][1];
        long long pick =  questions[ind][0] + solve(ind+add+1, questions, n, dp);
        long long notPick = 0 + solve(ind + 1, questions, n, dp);
        // cout<<pick<<" "<<notPick<<endl;
        return dp[ind] = max(pick, notPick);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        int ind = 0;
        vector<long long> dp(n+1, -1);
        return solve(ind, questions, n, dp);
    }
};
