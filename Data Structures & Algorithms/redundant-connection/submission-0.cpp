class Solution {
public:
    void make_set(int n, vector<int>& parent, vector<int>& size){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int find_set(int x, vector<int>& parent){
        return parent[x] = (parent[x] == x ? x : find_set(parent[x], parent));
    }

    bool union_set(int x, int y, vector<int>& parent, vector<int>& size){
        x = find_set(x, parent), y = find_set(y, parent);
        if(x == y) return false;

        if(size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        parent[y] = x;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        vector<int> parent, size;
        make_set(n, parent, size);

        for(auto& edge : edges) if(!union_set(edge[0], edge[1], parent, size)) return edge;
        
        return {};
        
    }
};
