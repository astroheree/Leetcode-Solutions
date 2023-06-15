class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int neg = 0, pos = 0;
        bool zeroCheck = false;
        int n = nums.size();
        if(n == 1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] > 0) pos++;
            else if(nums[i] == 0) zeroCheck = true;
            else neg++;
        }
        if(pos == 0 && zeroCheck == true && (neg == 1 || neg == 0))  return 0;
        if(neg % 2 != 0) neg--;
        long long ans = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(neg-- > 0) if(nums[i] != 0) ans *= nums[i];
            if(pos-- > 0) if(nums[n-i-1] != 0) ans *= nums[n-i-1];
        }
        return ans;
    }
    
};
