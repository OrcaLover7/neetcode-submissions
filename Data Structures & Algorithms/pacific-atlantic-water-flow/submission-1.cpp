class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = (int)heights.size();
        int n = (int)heights[0].size();

        vector<vector<int>> vp(m, vector<int>(n, 0));
        vector<vector<int>> va(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) q.push({i, 0});

        for(int j = 0; j < n; j++) q.push({0, j});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(vp[x][y]) continue;

            vp[x][y] = 1;

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(isValid(nx, ny, m, n) and !vp[nx][ny] and heights[nx][ny] >= heights[x][y]) q.push({nx, ny});
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) q.push({i, n-1});
        for(int j = 0; j < n; j++) q.push({m-1, j});
        

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(va[x][y]) continue;

            va[x][y] = 1;

            if(vp[x][y]) ans.push_back({x, y});

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(isValid(nx, ny, m, n) and !va[nx][ny] and heights[nx][ny] >= heights[x][y]) q.push({nx, ny});
            }
        }

        return ans;
    }
};
