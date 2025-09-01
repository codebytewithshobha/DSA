class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
        return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }
    
private:
    /* Helper function to find the number of 
    subarrays with sum less than or equal to `goal`*/
    int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal) {
        
        if (goal < 0) return 0;
        
        //Pointers to maintain the current window
        int l = 0, r = 0; 
        
        /* Variable to track the current 
        sum of elements in the window*/
        int sum = 0;      
        
        // Variable to count the number of subarrays
        int count = 0;   
        
        /* Iterate through the array 
        using the right pointer `r`*/
        while (r < nums.size()) {
            sum += nums[r]; 
            
            /* Shrink the window from the left
            side if the sum exceeds `goal`*/
            while (sum > goal) {
                sum -= nums[l];  
                
                // Move the left pointer `l` forward
                l++;            
            }
            
            /* Count all subarrays ending at
            `r` that satisfy the sum condition*/
            count += (r - l + 1);
            
            // Move the right pointer `r` forward 
            r++; 
        }
        
        // Return the total count of subarrays
        return count;
    }
};
