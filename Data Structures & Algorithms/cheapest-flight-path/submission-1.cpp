class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = INT_MAX;
        vector<int> dist(n, INF);

        dist[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> prev = dist;

            for(auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if(prev[u] != INF and prev[u] + w < dist[v]) dist[v] = prev[u] + w;
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
