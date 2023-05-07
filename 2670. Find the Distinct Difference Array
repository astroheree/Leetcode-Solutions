class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0 ;  i < nums.size() ; i++)m[nums[i]]++;
        
        map<int,int> na;
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++)
        {
            m[nums[i]]--;
            if(m[nums[i]] == 0)
            m.erase(nums[i]);
            
            na[nums[i]]++;
            ans[i] = na.size() - m.size();
            
        }
        return ans;
    }
};
