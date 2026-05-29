class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& req : prereq){
            graph[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++) if(!indegree[i]) q.push(i);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(auto& neigh : graph[curr]){
                int new_in = --indegree[neigh];
                if(!new_in) q.push(neigh);
            }
        }

        vector<int> empty;
        return (ans.size() == numCourses ? ans : empty);
    }
};
