class Solution {
public:
        int n, m;
    vector<vector<int>> pref;

    // build prefix sum array
    void buildPrefix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        pref.assign(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i+1][j+1] = grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j];
            }
        }
    }

    // get number of ones in sub-rectangle
    int getOnes(int r1, int c1, int r2, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1];
    }

    // get bounding box area of ones in a region
    int boundingBoxArea(int r1, int c1, int r2, int c2) {
        int minr = INT_MAX, maxr = INT_MIN, minc = INT_MAX, maxc = INT_MIN;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (getOnes(i,j,i,j)) {
                    minr = min(minr, i);
                    maxr = max(maxr, i);
                    minc = min(minc, j);
                    maxc = max(maxc, j);
                }
            }
        }
        if (minr == INT_MAX) return 0; // no ones
        return (maxr - minr + 1) * (maxc - minc + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        buildPrefix(grid);
        int ans = INT_MAX;

        // case 1: vertical splits
        for (int c1 = 0; c1 < m-2; c1++) {
            for (int c2 = c1+1; c2 < m-1; c2++) {
                int a = boundingBoxArea(0, 0, n-1, c1);
                int b = boundingBoxArea(0, c1+1, n-1, c2);
                int c = boundingBoxArea(0, c2+1, n-1, m-1);
                if (a && b && c) ans = min(ans, a+b+c);
            }
        }

        // case 2: horizontal splits
        for (int r1 = 0; r1 < n-2; r1++) {
            for (int r2 = r1+1; r2 < n-1; r2++) {
                int a = boundingBoxArea(0, 0, r1, m-1);
                int b = boundingBoxArea(r1+1, 0, r2, m-1);
                int c = boundingBoxArea(r2+1, 0, n-1, m-1);
                if (a && b && c) ans = min(ans, a+b+c);
            }
        }

        // case 3: mixed splits (vertical + horizontal)
        for (int r = 0; r < n-1; r++) {
            for (int c = 0; c < m-1; c++) {
                // partition into 3 regions in L-shape
                int a = boundingBoxArea(0, 0, r, m-1);       // top strip
                int b = boundingBoxArea(r+1, 0, n-1, c);     // bottom-left
                int d = boundingBoxArea(r+1, c+1, n-1, m-1); // bottom-right
                if (a && b && d) ans = min(ans, a+b+d);

                a = boundingBoxArea(0, 0, n-1, c);          // left strip
                b = boundingBoxArea(0, c+1, r, m-1);        // top-right
                d = boundingBoxArea(r+1, c+1, n-1, m-1);    // bottom-right
                if (a && b && d) ans = min(ans, a+b+d);

                a = boundingBoxArea(0, 0, r, c);            // top-left
                b = boundingBoxArea(0, c+1, r, m-1);        // top-right
                d = boundingBoxArea(r+1, 0, n-1, m-1);      // bottom strip
                if (a && b && d) ans = min(ans, a+b+d);

                a = boundingBoxArea(0, 0, r, c);            // top-left
                b = boundingBoxArea(r+1, 0, n-1, c);        // bottom-left
                d = boundingBoxArea(0, c+1, n-1, m-1);      // right strip
                if (a && b && d) ans = min(ans, a+b+d);
            }
        }

        return ans;
        
    }
};