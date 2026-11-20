class Solution {
public:
    void make_set(int n, vector<int>& parent, vector<int>& size){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 0;
        }
    }

    int find_set(int x, vector<int>& parent){
        if(parent[x] != x) return parent[x] = find_set(parent[x], parent);
        return x;
    }

    void union_sets(int x, int y, vector<int>& parent, vector<int>& size){
        x = find_set(x, parent), y = find_set(y, parent);
        if(x == y) return;
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0), size(n, 0);
        make_set(n, parent, size);

        unordered_set<int> component_parents;

        for(auto& edge : edges) union_sets(edge[0], edge[1], parent, size);

        for(int i = 0; i < n; i++) component_parents.insert(find_set(i, parent));

        return component_parents.size();
        
    }
};
