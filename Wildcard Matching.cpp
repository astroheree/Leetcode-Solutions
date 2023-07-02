class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1,0), curr(m+1,0);
        prev[0] = true;
        for(int j = 1 ; j <= m ; j++)
        {
            bool flag = true;
            for(int i = 0 ; i < j ; i++)
            {
                if(p[i] != '*') 
                {
                    flag = false;
                    break;   
                }
            }
            prev[j] = flag;
        }
        for(int ind1 = 1 ; ind1 <= n ; ind1++)
        {
            for(int ind2 = 1 ; ind2 <= m ; ind2++)
            {
                if(s[ind1-1] == p[ind2-1] || p[ind2-1] == '?')
                curr[ind2] = prev[ind2-1];

                else if(p[ind2-1] == '*')
                curr[ind2] = prev[ind2] || curr[ind2-1];

                else curr[ind2] = false;
            }
            prev = curr;
        }
        return prev[m];
        // return solve(n,m,s,p,dp);
    }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<bool>> dp(n+1, vector<bool>(m+1,0));
    //     dp[0][0] = true;
    //     for(int j = 1 ; j <= m ; j++)
    //     {
    //         bool flag = true;
    //         for(int i = 0 ; i < j ; i++)
    //         {
    //             if(p[i] != '*') 
    //             {
    //                 flag = false;
    //                 break;   
    //             }
    //         }
    //         dp[0][j] = flag;
    //     }
    //     for(int ind1 = 1 ; ind1 <= n ; ind1++)
    //     {
    //         for(int ind2 = 1 ; ind2 <= m ; ind2++)
    //         {
    //             if(s[ind1-1] == p[ind2-1] || p[ind2-1] == '?')
    //             dp[ind1][ind2] = dp[ind1-1][ind2-1];

    //             else if(p[ind2-1] == '*')
    //             dp[ind1][ind2] = dp[ind1-1][ind2] || dp[ind1][ind2-1];

    //             else dp[ind1][ind2] = false;
    //         }
    //     }
    //     return dp[n][m];
    //     // return solve(n,m,s,p,dp);
    // }
    // bool solve(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
    // {
    //     if(ind1 == 0 && ind2 == 0) return true;
    //     if(ind1 > 0 && ind2 == 0) return false;
    //     if(ind2 > 0 && ind1 == 0)
    //     {
    //         for(int i = 0 ; i < ind2 ; i++)
    //         if(p[i] != '*') return false;
    //         return true;
    //     }
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(s[ind1-1] == p[ind2-1] || p[ind2-1] == '?')
    //         return dp[ind1][ind2] = solve(ind1-1,ind2-1,s,p,dp);

    //     if(p[ind2-1] == '*')
    //     return dp[ind1][ind2] = solve(ind1-1,ind2,s,p,dp) || solve(ind1,ind2-1,s,p,dp);

    //     return dp[ind1][ind2] = false;

    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    //     return solve(n,m,s,p,dp);
    // }
};
