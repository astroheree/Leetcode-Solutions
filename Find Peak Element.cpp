class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 1 , e = n-2;
        int mid = s + (e-s)/2;
        if(n==1) return 0;
        if(nums[1] < nums[0]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        while(s<=e)
        {
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid+1]) s = mid + 1;
            else if(nums[mid] < nums[mid-1]) e = mid - 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }
};
