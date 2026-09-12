class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // One hash set per row, column, and box
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char digit = board[r][c];

                if (digit == '.') continue;  // skip empty cells

                int boxIndex = (r / 3) * 3 + (c / 3);

                // If digit already seen in this row, column, or box -> invalid
                if (rows[r].count(digit) || cols[c].count(digit) || boxes[boxIndex].count(digit)) {
                    return false;
                }

                // Mark digit as seen in all three
                rows[r].insert(digit);
                cols[c].insert(digit);
                boxes[boxIndex].insert(digit);
            }
        }

        return true;
    }
};