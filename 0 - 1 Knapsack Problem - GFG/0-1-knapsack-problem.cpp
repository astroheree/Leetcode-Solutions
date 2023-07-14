//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // int dp[1005][1005];
    //Function to return max value that can be put in knapsack of capacity W.
    // int solve(int i, int W, int wt[], int val[], int n)
    // {
    //     if(i == 0)
    //     {
    //         if(wt[0] <= W) return val[0];
    //         else return 0;
    //     }
    //     if(dp[i][W] != -1) return dp[i][W];
    //     int pick = -1e9;
    //     if(W >= wt[i])
    //         pick = val[i] + solve(i-1,W-wt[i],wt,val,n);
            
    //     int notPick = solve(i-1,W,wt,val,n);
    //     return dp[i][W] = max(pick,notPick);
    // }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W+1,0), curr(W+1,0);
        for(int i = wt[0] ; i <= W ; i++)
        {
            prev[i] = val[0];
        }
        for(int i = 1 ; i < n ; i++)
        {
            for(int w = 0 ; w <= W ; w++)
            {
                int pick = -1e9;
                if(w >= wt[i])
                    pick = val[i] + prev[w-wt[i]];
                    
                int notPick = prev[w];
                curr[w] = max(pick,notPick);
            }
            prev = curr;
        }
        return prev[W];
        // return solve(n-1,W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends