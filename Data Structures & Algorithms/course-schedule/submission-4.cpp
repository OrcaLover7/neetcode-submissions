class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& req : prereq){
            graph[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) if(!indegree[i]) q.push(i);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto& neigh : graph[curr]){
                indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }

        for(int i : indegree) if(i) return false;

        return true;
    }
};
