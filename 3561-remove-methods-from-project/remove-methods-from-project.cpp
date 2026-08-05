class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for(auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }


        
        vector<int> suspicious(n,0);

        queue<int> q;
        q.push(k);
        suspicious[k] = 1;


        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int next : graph[node]) {

                if(!suspicious[next]) {
                    suspicious[next] = 1;
                    q.push(next);
                }
            }
        }


        for(auto &edge : invocations) {

            int from = edge[0];
            int to = edge[1];

            if(!suspicious[from] && suspicious[to]) {

                vector<int> ans;

                for(int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }


        
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            if(!suspicious[i])
                ans.push_back(i);
        }


        return ans;
    }
};