class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX;
        vector<int> dist(n+1, INF);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        dist[k] = 0;

        vector<vector<pair<int, int>>> graph(n+1);

        for(auto& time : times) graph[time[0]].push_back({time[1], time[2]});

        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto [d, u] = min_heap.top();
            min_heap.pop();

            if(dist[u] < d) continue;

            for(auto [v, w] : graph[u]){
                int new_dist = dist[u] + w;

                if(dist[v] > new_dist){
                    dist[v] = new_dist;
                    min_heap.push({new_dist, v});
                }
            }
        }

        int ans = -1;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INF) return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
        
    }
};
