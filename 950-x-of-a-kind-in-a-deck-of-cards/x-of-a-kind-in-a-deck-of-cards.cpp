class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        for (int card : deck) {
            freq[card]++;
        }

        int g = 0;

        for (auto& p : freq) {
            g = gcd(g, p.second);

            if (g == 1)
                return false;
        }

        return g >= 2;
    }
};
