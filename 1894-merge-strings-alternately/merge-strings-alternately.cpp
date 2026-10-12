class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int i = 0, j = 0;
        string result = "";
        
        while(i<m && j<n){
            result += word1[i];
            i++;
            result += word2[j];
            j++;
        }
        while(i<m){
            result += word1[i];
            i++;
        }
        while(j<n){
            result += word2[j];
            j++;
        }
        return result;
    }
};