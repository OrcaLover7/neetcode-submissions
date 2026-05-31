class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto& req : prereqs){
            graph[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);

        vector<int> ans;

        while(!q.empty()){
            int crs = q.front();
            q.pop();
            ans.push_back(crs);

            for(auto& neigh : graph[crs]){
                indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }

        if((int)ans.size() != n) return {};

        return ans;
    }
};
