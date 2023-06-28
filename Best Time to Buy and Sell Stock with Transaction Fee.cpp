class Solution {
public:
int maxProfit (vector<int>& prices, int fee) {
vector<int> curr(2, 0), ahead (2,0);
int n = prices.size);
for(int ind = n-1 ; ind >= 0 ; ind--)
{
curr[1] = max(-prices [ind]+ahead[0],ahead[1]);
curr[0] = max(prices [ind]-fee+ahead[1], ahead[0]);
ahead = curr;
}
return curr[1];
}:
