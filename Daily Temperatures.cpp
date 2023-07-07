class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,0);
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            while((st.empty() == false) && (st.top().first <= arr[i]))
            {
                st.pop();
            }
            if(!st.empty() && st.top().first > arr[i]) ans[i] = st.top().second - i;
            st.push(make_pair(arr[i],i));
        }
        return ans;
    }
};
