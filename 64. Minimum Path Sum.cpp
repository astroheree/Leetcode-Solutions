class Solution {
public:
    // Space optimisation
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0),curr(m,0);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else
                {
                    int up = grid[i][j], left = grid[i][j];
                    if(i-1>=0) up += prev[j];
                    else up += 1e8;
                    if(j-1>=0) left += curr[j-1];
                    else left += 1e8;
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
        // return solve(grid,n-1,m-1,dp);
    }

    // memoization
    // int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>>&dp)
    // {
    //     if(i == 0 && j == 0) return grid[i][j];
    //     if(j<0 || i<0) return 1e9;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = grid[i][j] + solve(grid,i-1,j, dp);
    //     int left = grid[i][j] + solve(grid,i,j-1,dp);

    //     return dp[i][j] = min(up,left);
    // }
    
    // tabulation
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,0));
    //     for(int i = 0 ; i < n ; i++)
    //     {
    //         for(int j = 0 ; j < m ; j++)
    //         {
    //             if(i == 0 && j == 0) dp[i][j] = grid[i][j];
    //             else
    //             {
    //                 int up = grid[i][j], left = grid[i][j];
    //                 if(i-1>=0) up += dp[i-1][j];
    //                 else up += 1e8;
    //                 if(j-1>=0) left += dp[i][j-1];
    //                 else left += 1e8;
    //                 dp[i][j] = min(up,left);
    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    //     // return solve(grid,n-1,m-1,dp);
    // }
};
