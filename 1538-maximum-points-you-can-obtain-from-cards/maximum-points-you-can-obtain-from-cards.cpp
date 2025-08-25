class Solution {
public:
        int maxScore(vector<int>& cardScore, int k) {
        int lSum = 0, rSum = 0, maxSum = 0;

        // Calculate the initial sum of the first k cards
        for (int i = 0; i < k; i++) {
            lSum += cardScore[i];
            
            /* Initialize maxSum with the
            sum of the first k cards*/
            maxSum = lSum;
        }

        //Initialize rightIndex to iterate array from last
        int rightIndex = cardScore.size() - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            
            // Remove the score of the ith card from left sum
            lSum -= cardScore[i];   
            
            /* Add the score of the card
            from the right to the right sum*/
            rSum += cardScore[rightIndex];  
            
            // Move to the next card from the right
            rightIndex--; 

            // Update maxSum with the maximum sum found so far
            maxSum = max(maxSum, lSum + rSum);
        }

        // Return the maximum score found
        return maxSum; 
        
    }
};