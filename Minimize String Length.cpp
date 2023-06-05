class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char,int> m;
        for(int i = 0 ; i < s.size() ; i++) m[s[i]]++;
        return m.size();
    }
};
