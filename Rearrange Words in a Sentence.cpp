class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss(text); 
        string word = text;
        vector<string>strings;
        while(ss>>word) 
        strings.push_back(word);

        int spaceCount = strings.size();
        map<int,vector<string>> m;
        for(int i = 0 ; i < strings.size() ; i++)
        m[strings[i].size()].push_back(strings[i]);
        string ans;
        for(auto i: m)
        {
            for(auto j: i.second)
            {
                ans += j;
                if(spaceCount-- > 1)  ans += ' '; 
            }
        }
        ans[0] = toupper(ans[0]);
        for(int i = 1 ; i < ans.size() ; i++) ans[i] = tolower(ans[i]);
        
        return ans;
    }
};
