class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int count = 0;
        int n = nums.size(), index = -1;
        for(int i = 0 ; i < n ; i++)// 2 1 4 3
        {
            if(nums[i] == 1)
            {
                index = i;
                break;
            }
        }
        for(int i = index ; i > 0 ; i--)
        {
            swap(nums[i],nums[i-1]);
            count++;
        }
        
        for(int i =  0 ;i < n; i++)
        {
            if(nums[i] == n)
            {
                count+= n-i-1;
                break;
            }
        }
        return count;
    }
};
