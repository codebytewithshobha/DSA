class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n/2; 
        long long total = 0;
        for(int x : nums){
            total += x;
        }
        long long windowSum = 0;
        for(int i = 0; i < half; i++){
            windowSum += nums[i];  
        }
        int ans = 0;

        if(windowSum > total - windowSum){
            ans ++;
        }
        for( int i = 1; i <n; i++){
        windowSum -= nums[i-1];
        windowSum += nums[(i + half - 1) % n];
            if(windowSum > total - windowSum){
                ans++;
            }
        }
        return ans;
    }
};