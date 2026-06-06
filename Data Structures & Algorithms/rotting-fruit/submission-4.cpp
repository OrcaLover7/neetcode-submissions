class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int time = 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int sz = (int)q.size();
            for(int i = 0; i < sz; i++){
                auto [x, y] = q.front();
                q.pop();
                
                for(auto& [dx, dy] : directions){
                    int nx = x + dx;
                    int ny = y + dy;

                    if(isValid(nx, ny, m, n) && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            if(!q.empty()) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
