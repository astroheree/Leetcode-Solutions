class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2*k+1,0), ahead(2*k+1,0);
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int t = 2*k-1; t >= 0  ; t--)
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
