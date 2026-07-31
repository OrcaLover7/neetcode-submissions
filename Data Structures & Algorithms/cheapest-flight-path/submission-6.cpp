class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = INT_MAX;
        vector<int> dist(n, inf);
        
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++){
            vector<int> cpy = dist;

            for(auto& flight: flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if(cpy[u] != inf and cpy[u] + w < dist[v]) dist[v] = cpy[u] + w;
            }
        }

        return dist[dst] == inf ? -1 : dist[dst];
    }
};
