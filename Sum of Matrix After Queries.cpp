class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> visRow(n,1),visCol(n,1);
        int rowsLeft = n, colsLeft = n;
        long long sum = 0;
        for(int i = queries.size() - 1; i >= 0 ; i--)
        {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            if(type == 0)
            {
                if(visRow[index])
                {
                    sum += rowsLeft*val;
                    visRow[index] = 0;
                    colsLeft--;
                }
            }
            else
            {
                if(visCol[index])
                {
                    sum += colsLeft*val;
                    visCol[index] = 0;
                    rowsLeft--;
                }
            }
        }
        return sum;
    }
};
