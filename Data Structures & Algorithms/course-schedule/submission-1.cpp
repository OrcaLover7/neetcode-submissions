class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> graph;
        vector<int> indegree(numCourses, 0);

        for(auto& req : prerequisites) {
            graph[req[1]].insert(req[0]);
            indegree[req[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        if(q.empty()) return false;

        while(!q.empty()){
            int size = (int)q.size();

            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();

                for(auto& neigh : graph[curr]){
                    indegree[neigh]--;
                    if(!indegree[neigh]) q.push(neigh);
                }
            }
        }

        for(int i : indegree){
            if(i) return false;
        }

        return true;
    }
};
