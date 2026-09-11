class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // Step 2: Create buckets — index = frequency, value = list of numbers
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& entry : countMap) {
            int num = entry.first;
            int freq = entry.second;
            buckets[freq].push_back(num);
        }

        // Step 3: Collect top k starting from highest frequency
        vector<int> result;
        for (int i = (int)buckets.size() - 1; i >= 0 && (int)result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if ((int)result.size() == k) break;
            }
        }

        return result;
    }
};



        