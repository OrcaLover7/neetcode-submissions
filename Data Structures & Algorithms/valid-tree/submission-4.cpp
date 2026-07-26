class Solution {
public:

    void make_set(int n, vector<int>& parent, vector<int>& sz){
        parent.resize(n, -1);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find_set(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x], parent);
    }

    bool union_set(int x, int y, vector<int>& parent, vector<int>& sz){
        x = find_set(x, parent);
        y = find_set(y, parent);

        if(x == y) return true;

        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];

        parent[y] = x;

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if((int)edges.size() != n-1) return false;

        vector<int> parent, sz;

        make_set(n, parent, sz);

        for(auto& edge : edges) if(union_set(edge[0], edge[1], parent, sz)) return false;

        return true;
    }
};
