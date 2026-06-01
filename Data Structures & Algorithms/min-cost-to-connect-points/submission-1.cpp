class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<long long> dist(n, LLONG_MAX);
        vector<bool> in(n, false);

        long long cost = 0;
        dist[0] = 0;

        for(int i = 0; i < n; i++){
            int u = -1;

            for(int v = 0; v < n; v++) if(!in[v] && (u == -1 || dist[v] < dist[u])) u = v;

            in[u] = true;
            cost += dist[u];

            for(int w = 0; w < n; w++){
                if(in[w]) continue;

                long long d = abs(points[u][0] - points[w][0]) + abs(points[u][1] - points[w][1]);
                dist[w] = min(dist[w], d);
            }
        }

        return cost;
    }
};
