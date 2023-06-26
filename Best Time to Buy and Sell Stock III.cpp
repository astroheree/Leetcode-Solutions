class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(5,0), ahead(5,0);
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int t = 3; t >= 0  ; t--)
            {
                if(t%2 == 0)
                    curr[t] = max(-prices[ind] + ahead[t+1], curr[t]);
                else
                    curr[t] = max(prices[ind] + ahead[t+1],curr[t]);
            }
            ahead = curr;
        }
        return curr[0];
    }
};


// private:
//     int solve(int ind, int t, vector<int> &prices, int n, vector<vector<int>> &dp)
//     {
//         if(ind == n || t == 4) return 0;
//         if(dp[ind][t] != -1) return dp[ind][t];
//         if(t%2 == 0)
//         {
//             return dp[ind][t] = max(-prices[ind] + solve(ind+1,t+1,prices,n,dp), solve(ind+1,t,prices,n,dp));
//         }
//         return dp[ind][t] = max(prices[ind] + solve(ind+1,t+1,prices,n,dp),solve(ind+1,t,prices,n,dp));
//     }
