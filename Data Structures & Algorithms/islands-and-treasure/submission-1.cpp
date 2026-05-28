class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int inf = 2147483647;

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(grid[i][j] == 0) q.push({i, j});

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(isValid(nx, ny, m, n) && grid[nx][ny] == inf){
                    q.push({nx, ny});
                    grid[nx][ny] = grid[x][y] + 1;
                }

            }
        }

        return ;
    }
};
