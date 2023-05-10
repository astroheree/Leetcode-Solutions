class Solution {
public:
    char findIt(map<char,int> &m, int freq)
    {
        char ele;
        for(auto i: m)
            if(i.second == freq) ele = i.first;
        m[ele] = 0;
        return ele;
    }
    string frequencySort(string s) 
    {
        string ans;
        map<char,int> m;
        for(int i = 0 ; i < s.size() ; i++) m[s[i]]++;

        priority_queue<int> pq;
        for(auto i: m) pq.push(i.second);

        while(!pq.empty())
        {
            int freq = pq.top();
            pq.pop();
            char ch = findIt(m,freq);
            while(freq--) ans += ch;
        }
        return ans;
    }
};
