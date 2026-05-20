class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int ans = 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    int area = 1;

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(auto& [dx, dy] : directions){
                            int nx = x + dx;
                            int ny = y + dy;

                            if(isValid(nx, ny, m, n) && grid[nx][ny] == 1){
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                                area++;
                            }
                        }
                    }

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};
