class Solution {
public:
    //they wwant me to form one connected component that's clear
    //they wwant the minimum cost. each edge has wweight of manhattan distance
    //they also don't wnat cycles? (only one path between eahc pair)
    //they wwnat a valid tree with min. cost
    //can calculate manhattan distnace for every pair and also construct hte graph at the time
    //the one that has the min distance across all pair of points is the one that becomes the parent/root (in dsu)? not really gonna owrk 
    //when you take into account the potential need to connect to other points
    //minimum spanning tree?
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<long long> dist(n, LLONG_MAX);
        vector<bool> in_tree(n, false);

        dist[0] = 0;
        long long cost = 0;

        for(int edge_count = 0; edge_count < n; edge_count++){
            int u = -1;

            for(int v = 0; v < n; v++) if(!in_tree[v] && (u == -1 || dist[v] < dist[u])) u = v;
            
            in_tree[u] = true;
            cost += dist[u];

            for(int w = 0; w < n; w++){
                if(in_tree[w]) continue;
                long long d = abs(points[u][0] - points[w][0]) + abs(points[u][1] - points[w][1]);
                dist[w] = min(d, dist[w]);
            }
        }

        return cost;
    }
};
