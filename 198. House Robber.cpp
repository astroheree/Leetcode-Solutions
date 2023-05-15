class Solution {
public:
    //memoization
    // int solve(int i, vector<int> &nums , vector<int> &dp)
    // {
    //     if(i == 0) return nums[i];
    //     if(i<0) return 0;
    //     if(dp[i] != -1) return dp[i];

    //     int pick = nums[i] + solve(i-2, nums, dp);
    //     int nPick = solve(i-1,nums, dp);

    //     return dp[i] =  max(pick,nPick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0],prev2 = 0;
        for(int i = 1 ; i < n ; i++)
        {
            int pick = nums[i],nPick = 0;
            if(i-2>=0) pick += prev2;
            if(i-1>=0) nPick += prev;

            int curr = max(pick,nPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
