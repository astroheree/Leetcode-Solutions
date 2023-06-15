class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        m[arr[i]]++;

        priority_queue<int> pq;
        for(auto i: m)
        pq.push(i.second);
        int t = n;
        int count = 0;
        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            t -= top;
            count++;
            if(t<=n/2) break;
        }
        return count;
    }
    
};
