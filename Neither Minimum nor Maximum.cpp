class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mini = 101, maxi = 0;
        for(auto i:nums) 
        {
            if(mini>i) mini = i;

            if(maxi<i) maxi = i;
        }
        for(auto i:nums)
        {
            if(i != maxi && i != mini) return i;
        }
        return -1;    
    }
};
