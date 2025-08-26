class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = -1;  // store maximum diagonal squared
        int maxArea = -1;    // store area of rectangle with longest diagonal
        
        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diagSq = l * l + w * w; // squared diagonal
            int area = l * w;
            
            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq) {
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
        
    }
};