class Solution {
public:
    bool is_edge(int x, int y, int m, int n){
        return (x == 0 or x == m-1 or y == 0 or y == n-1);
    }

    bool is_valid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        int n = (int)board[0].size();

        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(is_edge(i, j, m, n) and board[i][j] == 'O') q.push({i, j});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(board[x][y] == 'z') continue;
            board[x][y] = 'z';

            for(auto& [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(is_valid(nx, ny, m, n) and board[nx][ny] == 'O') q.push({nx, ny});
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'z') board[i][j] = 'O';
            }
        }

        return;
    }
};
