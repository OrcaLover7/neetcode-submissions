class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses, 0);
        unordered_map<int, vector<int>> graph;

        for(auto& prereq : prerequisites) {
            inorder[prereq[0]]++;
            graph[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            if(!inorder[i]){
                ans.push_back(i);
                q.push(i);
            }
        }

        if(!q.size()) return {}; 

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& kid : graph[node]){
                inorder[kid]--;
                if(!inorder[kid]){
                    ans.push_back(kid);
                    q.push(kid);
                }
            }

        }

        for(int i = 0; i < numCourses; i++){
            if(inorder[i]) return {};
        }

        return ans;
    }
};
