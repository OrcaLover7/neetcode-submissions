class Solution {
public:
    void make_set(vector<int>& parent, vector<int>& size, int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        else return parent[x] = find_set(parent[x], parent);
    }

    bool union_sets(int x, int y, vector<int>& parent, vector<int>& size){
        x = find_set(x, parent), y = find_set(y, parent);
        if(x == y) return false;
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1), size(n, -1);
        make_set(parent, size, n);
        int components = n;
        for(auto& edge : edges){
            if(union_sets(edge[0], edge[1], parent, size)) components--;
            else return false;
        }

        return components == 1;
    }
};
