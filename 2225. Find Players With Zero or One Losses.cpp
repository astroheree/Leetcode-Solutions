class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m2;
        vector<vector<int>> ans;
        set<int> first;
        for(int i = 0  ; i < matches.size() ; i++)
        {
            first.insert(matches[i][0]);
            m2[matches[i][1]]++;
        }
        vector<int> noLoss;
        for(auto i: first)
        {
            if(m2.find(i) == m2.end()) noLoss.push_back(i);
        }
        ans.push_back(noLoss);
        noLoss.clear();
        for(auto i: m2)
        {
            if(i.second == 1) noLoss.push_back(i.first);
        }
        ans.push_back(noLoss);
        return ans;
    }
};
