class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<long long> dist(n, LLONG_MAX);
        vector<bool> in(n, false);

        dist[0] = 0;
        
        long long cost = 0;

        for(int i = 0; i < n; i++){
            int u = -1;

            for(int v = 0; v < n; v++) if(!in[v] and (u == -1 or dist[v] < dist[u])) u = v;

            cost += dist[u];
            in[u] = true;

            for(int w = 0; w < n; w++){
                if(in[w]) continue;

                long long d = abs(points[w][0] - points[u][0]) + abs(points[w][1] - points[u][1]);
                dist[w] = min(dist[w], d);
            }
            
        }

        return (int)cost;
    }
};
