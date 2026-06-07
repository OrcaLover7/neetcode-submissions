class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX);

        for(auto& time : times) graph[time[0]].push_back({time[1], time[2]});

        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto [d, u] = min_heap.top();
            min_heap.pop();

            if(dist[u] < d) continue;

            for(auto [v, w] : graph[u]){
                int new_dist = d + w;
                if(new_dist < dist[v]){
                    dist[v] = new_dist;
                    min_heap.push({new_dist, v});
                }
            }
        }


        int ans = -1;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
