class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        vector<int> indegree(numCourses, 0);

        for(auto& prereq : prerequisites){
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) if(!indegree[i]) q.push(i);

        int count = 0;


        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int neigh : graph[node]) if(!--indegree[neigh]) q.push(neigh);
        }

        return count == numCourses;
    }
};
