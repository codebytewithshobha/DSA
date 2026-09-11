class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> m;
        for(int x: nums){
            m[x]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto& [nu,fr]:m){
            q.push({fr,nu});
        }
        vector<int> a;
        while(k--){
            a.push_back(q.top().second);
            q.pop();
        }
return a;
    }
};