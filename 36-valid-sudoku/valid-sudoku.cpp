class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                // Ignore empty cells
                if (board[row][col] == '.') {
                    continue;
                }

                char num = board[row][col];

                // Find the 3x3 box
                int box = (row / 3) * 3 + (col / 3);

                // Check duplicate in row
                if (rows[row].count(num)) {
                    return false;
                }

                // Check duplicate in column
                if (cols[col].count(num)) {
                    return false;
                }

                // Check duplicate in box
                if (boxes[box].count(num)) {
                    return false;
                }

                // Store the number
                rows[row].insert(num);
                cols[col].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};