class Solution {
public:
    void make_set(int n, vector<int>& parent, vector<int>& size){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int x, vector<int>& parent){
        if(parent[x] != x) return parent[x] = find_set(parent[x], parent);
        return x;
    }

    bool union_sets(int x, int y, vector<int>& parent, vector<int>& size){
        x = find_set(x, parent), y = find_set(y, parent);
        if(x == y) return false;
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        vector<int> parent(n + 1, 0), size(n + 1, 0);

        make_set(n, parent, size);

        for(auto& edge : edges){
            if(!union_sets(edge[0], edge[1], parent, size)) return edge;
        }

        return {};
    }
};
