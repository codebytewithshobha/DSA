class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int baseScore = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1])
            {
                baseScore++;
                
            }
        }
        int ans = 0;
        if(baseScore == k) {
            ans++;
        }
        int newPair = (s[0] == s[n-1]);
        for(int p = 1; p <n; p++){
            int removePair = (s[p-1] == s[p]);
            int score = baseScore - removePair+newPair;
            if(score == k){
                ans++;
            }
        }
        return ans;
        }
};
        