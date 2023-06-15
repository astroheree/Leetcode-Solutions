class Solution {
public:
    int findIt(int e, unordered_map<int,int> &m)
    {
        int index = -1;
        for(auto i: m)
        {
            if(i.second == e)
            {
                index = i.first;
                break;
            }
        }
        m.erase(index);
        return index;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i: nums) m[i]++;
        priority_queue<int> pq;
        for(auto i: m) pq.push(i.second);
        vector<int> ans;
        while(!pq.empty() && k--)
        {
            int top = pq.top();
            pq.pop();
            int ele = findIt(top,m);
            ans.push_back(ele);
        }
        return ans;
    }
};
