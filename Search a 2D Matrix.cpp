class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int start = 0 , end = row*col - 1;
        int mid = start + (end-start)/2;
        int rInd, cInd;
        while(start <= end)
        {
            rInd = mid/col;
            cInd = mid%col;
            if(matrix[rInd][cInd] == target) return true;
            else if(matrix[rInd][cInd] > target) end = mid-1;
            else start = mid  + 1;
            
            mid = start+(end-start)/2;
        }
        return false;
    }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int row = matrix.size(), col = matrix[0].size();
    //     int i = 0 , j = col - 1;
    //     while(i < row && j >= 0)
    //     {
    //         if(matrix[i][j] == target) return true;
    //         else if(matrix[i][j] > target) j--;
    //         else i++;
    //     }
    //     return false;
    // }
};
