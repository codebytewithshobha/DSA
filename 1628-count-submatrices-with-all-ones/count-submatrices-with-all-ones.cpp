#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int total = 0;

        for (int i = 0; i < m; i++) {
            // update histogram heights
            for (int j = 0; j < n; j++) {
                height[j] = (mat[i][j] == 0 ? 0 : height[j] + 1);
            }

            // count submatrices in histogram
            total += countRow(height);
        }
        return total;
    }

private:
    int countRow(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        vector<int> sum(n, 0);
        int res = 0;

        for (int j = 0; j < n; j++) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();

            if (!st.empty()) {
                int prev = st.top();
                sum[j] = sum[prev] + h[j] * (j - prev);
            } else {
                sum[j] = h[j] * (j + 1);
            }

            res += sum[j];
            st.push(j);
        }
        return res;
    }
};
