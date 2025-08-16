class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int ones = 0, twos = 0;
        
        // Traverse the array 
        for(int i=0; i < nums.size(); i++) {
            // Add the number to Ones, it is not in Twos
            ones = (ones ^ nums[i]) & ~twos;
            
            // Add the number to Twos, if it is already in Ones
            twos = (twos ^ nums[i]) & ~ones;
        }
        
        return ones;
        
    }
};