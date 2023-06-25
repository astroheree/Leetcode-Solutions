class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0), ahead(2,0);
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            curr[1] = max(-prices[ind] + ahead[0], ahead[1]);
            curr[0] = max(prices[ind] + ahead[1],ahead[0]);
            ahead = curr;
        }
        return curr[1];
    }
};


// private:
//     int solve(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
//     {
//         if(ind == n) return 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         if(buy)
//         return dp[ind][buy] = max(-prices[ind] + solve(ind+1,0,prices,n,dp), solve(ind+1,1,prices,n,dp));

//         return dp[ind][buy] = max(prices[ind] + solve(ind+1,1,prices,n,dp),solve(ind+1,0,prices,n,dp));
//     }
