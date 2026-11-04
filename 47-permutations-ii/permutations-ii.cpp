
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, vector<bool>& used) {

        // Base case
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i]) {
                continue;
            }

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }

            // Choose
            used[i] = true;
            temp.push_back(nums[i]);

            solve(nums, used);

            // Undo choice
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);

        solve(nums, used);

        return ans;
    }
};
