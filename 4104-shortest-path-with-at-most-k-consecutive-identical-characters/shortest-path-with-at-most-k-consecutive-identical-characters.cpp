class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

   vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][c] stores the min weight to reach node 'u' 
        // with 'c' consecutive characters of labels[u]
        // Initialize all distances to a large value (infinity)
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Priority queue for Dijkstra: stores {weight, node, consecutive_count}
        // Min-heap ordered by the weight
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;

        // Base case: start at node 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            // If we found a shorter path to 'u' already, skip this stale state
            if (d > dist[u][count]) continue;

            // If we reached the target node, since it's Dijkstra, this is the minimum weight
            if (u == n - 1) return d;

            // Explore neighbors
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int next_count = 1;
                // If the neighbor has the exact same character label
                if (labels[v] == labels[u]) {
                    next_count = count + 1;
                }

                // If the consecutive count exceeds k, this path variation is illegal
                if (next_count > k) continue;

                // Relaxation step
                if (d + weight < dist[v][next_count]) {
                    dist[v][next_count] = d + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        // If node n-1 is unreachable within the rules
        return -1;
    }
};