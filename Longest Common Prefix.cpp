class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0] , last = strs[n-1];
        for(int i = 0 ; i < first.size() ; i++)
        {
            if(first[i] == last[i]) ans += last[i];
            else
            break;
        }
        return ans;
    }
};
