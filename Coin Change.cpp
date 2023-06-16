class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1,0);
        for(int tar = 0 ; tar <= amount ; tar++)
        {
            if(tar % coins[0] == 0) prev[tar] = tar/coins[0];
            else prev[tar] = 1e9;
        }
        for(int ind = 1 ; ind < n ; ind++)
        {
            for(int tar = 0 ; tar <= amount ; tar++)
            {
                int notPick = prev[tar];
                int pick = 1e9;
                if(coins[ind] <= tar) pick = 1 + curr[tar-coins[ind]];

                curr[tar] = min(pick,notPick);
            }
            prev = curr;
        }
        if(prev[amount] >=1e9) return -1;
        else return prev[amount];
    
        // int ans = solve(n-1,coins,amount,dp);
        // if(ans >= 1e9) return -1;
        // else return ans;
    }
    //memoization
    // int solve(int ind, vector<int>& coins, int x, vector<vector<int>> &dp)
    // {
    //     if(ind == 0)
    //     {
    //         if(x % coins[ind] == 0) return x/coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][x] != -1) return dp[ind][x];
    //     int notPick = solve(ind-1,coins,x, dp);
    //     int pick = 1e9;
    //     if(coins[ind] <= x) pick = 1 + solve(ind,coins,x-coins[ind],dp);

    //     return dp[ind][x] =  min(pick,notPick);
    // }
};
