class Solution {
public:
    string countAndSay(int n) {
    string result = "1"; // Base case

    for (int i = 1; i < n; i++) {
        string current = "";
        int count = 1; // Count of current digit

        for (int j = 1; j <= result.size(); j++) {
            if (j < result.size() && result[j] == result[j - 1]) {
                count++; // Increment count for same digit
            } else {
                current += to_string(count) + result[j - 1];
                count = 1; // Reset count
            }
        }

        result = current; // Move to next sequence
    }

    return result;
}
};