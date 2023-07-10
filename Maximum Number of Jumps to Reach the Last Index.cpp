class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int i=1 ; i<n ; i++)
        {
            int ans = -1e9;
            for(int k = i-1 ; k >= 0 ; k--)
            {
                if(abs(nums[i] - nums[k]) <= target)
                {
                    ans = max(ans,1+dp[k]);
                }
            }
            if(abs(nums[i] - nums[i-1]) <= target)
            {
                ans = max(ans,dp[i-1]);
            }
            dp[i] = ans;
        }
        if(dp[n-1] < 0) return -1;
        return dp[n-1];
    }
    // int dp[1001];
    // int n;
    // int rec(int i,vector<int>& nums, int target){
    //     // base
    //     if(i == 0){
    //         return 0;
    //     }
    //     // if(i < 0){
    //     //     return -1e9;
    //     // }
    //     // cache
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     // compute
    //     int ans = -1e9;
    //     // take
    //     for(int k=1;k<n;k++){
    //         if(i-k >= 0){
    //             if(abs(nums[i] - nums[i-k]) <= target){
    //                 ans = max(ans,1+rec(i-k,nums,target));
    //             }
    //         }
    //     }
    //     // not take
    //     if(abs(nums[i] - nums[i-1]) <= target){
    //         ans = max(ans,rec(i-1,nums,target));
    //     }
    //     // save n return
    //     return dp[i] = ans;
    // }

};
