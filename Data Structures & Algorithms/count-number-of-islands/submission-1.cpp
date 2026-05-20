class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        stack<pair<int, int>> st;
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0,1}};
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    st.push({i, j});
                    grid[i][j] = '0';

                    while(!st.empty()){
                        auto [x, y] = st.top();
                        st.pop();
                        grid[x][y] = '0';

                        for(auto& [dx, dy] : directions){
                            int nx = x + dx;
                            int ny = y + dy;

                            if(isValid(nx, ny, m, n) && grid[nx][ny] == '1') st.push({nx, ny});
                        }
                    }
                }
            }
        }

        return count;
    }
};
