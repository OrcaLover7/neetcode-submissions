class Solution {
public:
    vector<int> parent, rank;

    void make_set(int n){
        parent.resize(n, -1);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find_set(int a){
        if(parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }

    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return true;
        if(rank[a] < rank[b]) swap(a, b);
        rank[a] += rank[b];
        parent[b] = a;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int edge_count = (int)edges.size();
        if(edge_count != n-1) return false;

        make_set(n);

        for(auto& edge : edges){
            bool cycle = union_set(edge[0], edge[1]);
            if(cycle) return false;
        }

        int par = find_set(0);

        for(int i = 1; i < n; i++) if(par != find_set(i)) return false;

        return true;
    }
};
