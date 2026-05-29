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

        for(int i = 0; i < numCourses; i++){
            if(!indegree[i]){
                ans.push_back(i);
                q.push(i);
            }
        }

        if(q.size() == 0) return ans;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto& neigh : graph[curr]){
                int new_in = --indegree[neigh];
                if(!new_in){
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
        vector<int> empty;
        return (ans.size() == numCourses ? ans : empty);
    }
};
