class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int INF = 2147483647;

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(!grid[i][j]) q.push({i, j});
        
        vector<pair<int, int>> directions = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(isValid(nx, ny, m, n) and grid[nx][ny] == INF){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }

        }

        return;
    }
};
