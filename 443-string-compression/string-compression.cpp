class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while (i < n) {
            int j = i;

            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            int len = j - i;

            chars[index++] = chars[i];

            if (len > 1) {
                string count = to_string(len);

                for (char c : count) {
                    chars[index++] = c;
                }
            }

            i = j;
        }

        return index;
    }
};
