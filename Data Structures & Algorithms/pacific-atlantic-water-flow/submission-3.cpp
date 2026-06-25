class Solution {
public:
    bool is_valid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = (int)heights.size();
        int n = (int)heights[0].size();

        vector<vector<int>> v_a(m, vector<int>(n, 0));
        vector<vector<int>> v_p(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) q.push({i, 0});
        for(int j = 0; j < n; j++) q.push({0, j});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(v_p[x][y]) continue;
            v_p[x][y] = 1;

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(is_valid(nx, ny, m, n) and heights[x][y] <= heights[nx][ny]) q.push({nx, ny});
            }
        }

        for(int i = 0; i < m; i++) q.push({i, n-1});
        for(int j = 0; j < n; j++) q.push({m-1, j});

        vector<vector<int>> ans;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(v_a[x][y]) continue;
            v_a[x][y] = 1;
            if(v_p[x][y]) ans.push_back({x, y});

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(is_valid(nx, ny, m, n) and heights[x][y] <= heights[nx][ny]) q.push({nx, ny});
            }
        }

        return ans;
    }
};
