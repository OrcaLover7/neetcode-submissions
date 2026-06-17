class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = INT_MAX;
        vector<int> dist(n, INF);

        dist[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> dist_copy = dist;

            for(auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if(dist_copy[u] != INF and dist_copy[u] + w < dist[v]) dist[v] = dist_copy[u] + w;
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
