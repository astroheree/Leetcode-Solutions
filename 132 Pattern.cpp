class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int thirdElement = INT_MIN;
        stack<int> st;
        int n = nums.size();
        for(int i = n-1 ;i >= 0 ; i--)
        {
            if(thirdElement > nums[i]) return true;
            while(!st.empty() && st.top() < nums[i])
            {
                thirdElement = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
