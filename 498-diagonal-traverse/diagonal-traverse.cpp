class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        int row = 0, col = 0;
        bool up = true; // direction flag
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (up) { // moving up-right
                if (col == n - 1) {  // hit right boundary
                    row++;
                    up = false;
                } else if (row == 0) {  // hit top boundary
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else { // moving down-left
                if (row == m - 1) { // hit bottom boundary
                    col++;
                    up = true;
                } else if (col == 0) { // hit left boundary
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};
