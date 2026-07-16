class Solution {
public:
    void make_set(int n, vector<int>& parent){
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find_set(int x, vector<int>& parent){
        return parent[x] = (x == parent[x] ? x : find_set(parent[x], parent));
    }

    bool union_set(int x, int y, vector<int>& parent, vector<int>& sz){
        x = find_set(x, parent);
        y = find_set(y, parent);

        if(x == y) return false;

        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = (int)edges.size();
        vector<int> parent(n+1, 0), sz(n+1, 1);

        make_set(n, parent);

        for(auto& edge : edges) if(!union_set(edge[0], edge[1], parent, sz)) return edge;
        
        return {};
    }
};
