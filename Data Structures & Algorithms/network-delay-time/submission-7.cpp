class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX;
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INF);

        for(auto& time : times) graph[time[0]].push_back({time[1], time[2]});
        
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto [d, u] = min_heap.top();
            min_heap.pop();

            if(d > dist[u]) continue;

            for(auto& [v, w] : graph[u]){
                int dv = dist[u] + w;
                if(dv < dist[v]){
                    dist[v] = dv;
                    min_heap.push({dv, v});
                }
            }
        }

        int ans = -1;

        for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);

        return ans == INF ? -1 : ans;
    }
};
