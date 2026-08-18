class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

        for(auto& time : times) graph[time[0]].push_back({time[1], time[2]});
        dist[k] = 0;
        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto [d, u] = min_heap.top();
            min_heap.pop();

            if(dist[u] < d) continue;

            for(auto& [v, w] : graph[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    min_heap.push({dist[v], v});
                }
            }
        }

        int ans = -1;

        for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);

        return ans == INT_MAX ? -1 : ans;

    }
};
