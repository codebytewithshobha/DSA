class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int l = 0, r = n-1, pos = n-1;
        while( l <= r){
           int leftmost = nums[l]* nums[l];
           int rightmost = nums[r]*nums[r];
            if(leftmost > rightmost){
                ans[pos] = leftmost;
                l++;
            }else{
                ans[pos]= rightmost;
                r--;
            }
            pos--;
        }
        return ans;   
    }
};