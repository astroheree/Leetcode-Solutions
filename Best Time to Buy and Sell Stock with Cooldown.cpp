class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> curr(2, 0), front1(2,0),front2(2,0);
        int n = prices.size();
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            curr[1] = max(-prices[ind]+front1[0],front1[1]);
            curr[0] = max(prices[ind]+front2[1], front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};
