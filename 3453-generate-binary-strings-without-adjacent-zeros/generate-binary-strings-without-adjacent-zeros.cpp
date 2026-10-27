class Solution {
public:
    void build(int n, string& curr, vector<string>& res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        // Always allowed: append '1'
        curr.push_back('1');
        build(n, curr, res);
        curr.pop_back();

        // Append '0' only if the previous character is not '0'
        if (curr.empty() || curr.back() != '0') {
            curr.push_back('0');
            build(n, curr, res);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        string curr = "";

        build(n, curr, res);

        return res;
    }
};
