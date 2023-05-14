class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        vector<int> unvisited(n,-1);
        int dist = k;
        int pos = 1;
        for(int i=1; i<=n; i++)
        {
             if(pos%n != 0)
            {
                if(unvisited[(pos%n)-1] != -1) 
                break;
            }
            else
            {
                if(unvisited[n-1] != -1) 
                break;
            }
            
            if((pos)%n == 0)
            {
                unvisited[n-1] = i;
            }
            else
            {
            unvisited[(pos%n) - 1] = i;
            }
    
            dist = k*(i);
            pos = pos+dist;
        }
        for(int i=0; i<n; i++)
        {
            if(unvisited[i] == -1)
                ans.push_back(i+1);
        }
        return ans;
    }
};
