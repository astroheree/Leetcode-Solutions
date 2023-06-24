class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j = 0 ; j <= m ; j++) prev[j] = j;

        for(int ind1 = 1;  ind1 <= n ; ind1++)
        {
            curr[0] = ind1;
            for(int ind2 = 1; ind2<= m ;ind2++)
            {
                if(word1[ind1-1] == word2[ind2-1]) curr[ind2] = prev[ind2-1];
                else
                curr[ind2] = 1 + min(curr[ind2-1],min(prev[ind2],prev[ind2-1]));
            }
            prev = curr;
        }
        if(n == 0) return m;
        if(m == 0) return n;
        return curr[m];
    }

// private:
//     int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
//     {
//         if(ind1 == 0) return ind2;
//         if(ind2 == 0) return ind1;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(s[ind1-1] == t[ind2-1]) return dp[ind1][ind2] = solve(ind1-1,ind2-1, s,t,dp);
//         return dp[ind1][ind2] = min(1+solve(ind1,ind2-1,s,t,dp), min(1 + solve(ind1-1,ind2,s,t,dp), 1 + solve(ind1-1,ind2-1,s,t,dp)));
//     }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    //     for(int i = 0 ; i <= n ; i++) dp[i][0] = i;
    //     for(int j = 0 ; j <= m ; j++) dp[0][j] = j;

    //     for(int ind1 = 1;  ind1 <= n ; ind1++)
    //     {
    //         for(int ind2 = 1; ind2<= m ;ind2++)
    //         {
    //             if(word1[ind1-1] == word2[ind2-1]) dp[ind1][ind2] = dp[ind1-1][ind2-1];
    //             else
    //             dp[ind1][ind2] = 1 + min(dp[ind1][ind2-1],min(dp[ind1-1][ind2],dp[ind1-1][ind2-1]));
    //         }
    //     }
    //     return dp[n][m];
    // }
};
