class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(int i = 0 ; i < s.size() ; i++) m[s[i]]++;
        string ans ;
        for(int i = 0 ; i < order.size(); i++)
        {
            if(m.find(order[i]) != m.end())
            {
                int times = m[order[i]];
                while(times--)
                ans += order[i];
                m[order[i]] = 0;
            }
        }
        for(auto i: m)
        {
            int times = i.second;
            while(times--)
            ans += i.first;
        }
        return ans;
    }
};
