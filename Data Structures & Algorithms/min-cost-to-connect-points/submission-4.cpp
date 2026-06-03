class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<long long> dist(n, LLONG_MAX);
        long long cost = 0;
        vector<bool> in_tree(n, false);

        dist[0] = 0;

        for(int i = 0; i < n; i++){
            int u = -1;

            for(int v = 0; v < n; v++) if(!in_tree[v] && (u == -1 || dist[v] < dist[u])) u = v;

            in_tree[u] = true;
            cost += dist[u];

            for(int w = 0; w < n; w++){
                if(in_tree[w]) continue;
                long long d = abs(points[w][0] - points[u][0]) + abs(points[w][1] - points[u][1]);
                dist[w] = min(dist[w], d);
            }
        }

        return (int)cost;
    }
};
