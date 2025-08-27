class Solution {
public:
    int nextVal(int x) {
    if (x == 1) return 2;
    if (x == 2) return 0;
    return 2; // x == 0
}

int lenOfVDiagonal(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int n = grid.size(), m = grid[0].size();

    // directions: 0: ↘ (1,1), 1: ↙ (1,-1), 2: ↖ (-1,-1), 3: ↗ (-1,1)
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, -1, 1};
    int turn[4] = {1, 2, 3, 0}; // clockwise turn mapping

    // dpF[d][i][j] = longest alternating sequence starting at (i,j) moving in dir d
    vector<vector<vector<int>>> dpF(4, vector<vector<int>>(n, vector<int>(m, 1)));
    for (int d = 0; d < 4; ++d) {
        int is = (dx[d] == 1 ? n - 1 : 0);
        int ie = (dx[d] == 1 ? -1 : n);
        int js = (dy[d] == 1 ? m - 1 : 0);
        int je = (dy[d] == 1 ? -1 : m);
        for (int i = is; i != ie; i -= dx[d]) {
            for (int j = js; j != je; j -= dy[d]) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (grid[ni][nj] == nextVal(grid[i][j])) {
                        dpF[d][i][j] = 1 + dpF[d][ni][nj];
                    }
                }
            }
        }
    }

    // dpEnd1[d][i][j] = longest alternating sequence that ENDS at (i,j) along dir d and STARTS with 1
    vector<vector<vector<int>>> dpEnd1(4, vector<vector<int>>(n, vector<int>(m, 0)));
    for (int d = 0; d < 4; ++d) {
        int istart = (dx[d] == 1 ? 0 : n - 1);
        int iend   = (dx[d] == 1 ? n : -1);
        int jstart = (dy[d] == 1 ? 0 : m - 1);
        int jend   = (dy[d] == 1 ? m : -1);
        int istep  = (dx[d] == 1 ? 1 : -1);
        int jstep  = (dy[d] == 1 ? 1 : -1);

        for (int i = istart; i != iend; i += istep) {
            for (int j = jstart; j != jend; j += jstep) {
                if (grid[i][j] == 1) dpEnd1[d][i][j] = 1;

                int pi = i - dx[d], pj = j - dy[d];
                if (pi >= 0 && pi < n && pj >= 0 && pj < m &&
                    grid[i][j] == nextVal(grid[pi][pj])) {

                    if (grid[pi][pj] == 1) {
                        dpEnd1[d][i][j] = max(dpEnd1[d][i][j], 2);
                    }
                    if (dpEnd1[d][pi][pj] > 0) {
                        dpEnd1[d][i][j] = max(dpEnd1[d][i][j], dpEnd1[d][pi][pj] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    // straight (no turn)
    for (int d = 0; d < 4; ++d)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, dpEnd1[d][i][j]);

    // V-shaped with one clockwise turn at (i,j)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < 4; ++d) {
                if (dpEnd1[d][i][j] > 0) {
                    int d2 = turn[d];
                    ans = max(ans, dpEnd1[d][i][j] + dpF[d2][i][j] - 1);
                }
            }
        }
    }

    return ans;
}
};