class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,-1));
        int startRow = 0, startCol = 0, endRow = n-1, endCol = n-1;
        int count = 1;
        while(count <= n*n)
        {
            for(int i = startCol ; i <= endCol ; i++)
            {
                if(count <= n*n)
                {
                    matrix[startRow][i] = count++;
                }
            }
            startRow++;
            for(int i = startRow ; i <= endRow ; i++)
            {
                if(count <= n*n)
                matrix[i][endCol] = count++;
            }
            endCol--;
            for(int i = endCol ; i >= startCol ; i--)
            {
                if(count <= n*n)
                matrix[endRow][i] = count++;
            }
            endRow--;
            for(int i = endRow ; i >= startRow ; i--)
            {
                if(count <= n*n)
                matrix[i][startCol] = count++;
            }
            startCol++;
        }   
        return matrix;
    }
};
