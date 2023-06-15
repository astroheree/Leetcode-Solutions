class Solution {
public:
    void reverse(int s , int e, vector<int> &nums)
    {
        while(s<e)
        swap(nums[s++],nums[e--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
        return;
        if(k > n) k = k%n;
        k = n-k;
        reverse(0, k-1, nums);
        reverse(k,n-1,nums);
        reverse(0,n-1,nums);
        return;
    }
};
