class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int row = 0;
        while( top <= bottom ) {
            row = (top + bottom) / 2;
            int lastCol = matrix[row].size() - 1;

            if( target > matrix[row][lastCol] ) {
                top = row + 1;
            } else if( target < matrix[row][0] ) {
                bottom = row - 1;
            } else {
                break;
            }
        }

        if (top > bottom) return false;

        int left = 0;
        int right = matrix[0].size() - 1;

        while( left <= right ) {
            int mid = (left + right) / 2;

            if( target == matrix[row][mid] ) {
                return true;
            } else if( target > matrix[row][mid] ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};