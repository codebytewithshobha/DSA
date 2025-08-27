class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();  
        
        /* Variable to store the 
        maximum length of substring*/
        int maxLen = 0;  
        
        /* Map to track the count of each
        fruit type in the current window*/
        unordered_map<int, int> mpp;
        
        // Pointers for the sliding window approach
        int l = 0, r = 0;
        
        while(r < n){
            mpp[fruits[r]]++;
            
            /* If number of different fruits exceeds
             2 shrink the window from the left*/
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            
            /* If number of different fruits 
            is at most 2, update maxLen*/
            if(mpp.size() <= 2){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        // Return the maximum fruit
        return maxLen;
    }
};
