class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maximum = 0;

        for (string sentence : sentences) {
            int count = 1;

            for (char ch : sentence) {
                if (ch == ' ') {
                    count++;
                }
            }

            maximum = max(maximum, count);
        }

        return maximum;
    }
};