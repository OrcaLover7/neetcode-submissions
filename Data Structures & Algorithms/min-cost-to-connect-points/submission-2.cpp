class Solution {
public:

    void make_set(int n, vector<int>& parent, vector<int>& sz){
        parent.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find_set(int x, vector<int>& parent){
        return parent[x] = (parent[x] == x) ? x : find_set(parent[x], parent);
    }

    bool union_set(int x, int y, vector<int>& parent, vector<int>& sz){
        x = find_set(x, parent);
        y = find_set(y, parent);

        if(x == y) return false;

        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        parent[y] = x;

        return true;
    } 

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();

        vector<int> parent, sz;
        vector<array<int, 3>> edges;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({w, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        make_set(n, parent, sz);

        int cost = 0;

        for(auto& [w, i, j] : edges){
            if(union_set(i, j, parent, sz)){
                cost += w;
            }
        }

        return cost;
    }
};
