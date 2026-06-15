class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = (int)board.size();
        int n = (int)board[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(bt(board, word, v, 0, i, j, m, n, directions)) return true;

        return false;
    }

    bool bt(vector<vector<char>>& board, string& word, vector<vector<int>>& v, int index, int x, int y, int m, int n, vector<pair<int, int>>& directions){
        if(index == (int)word.size()) return true;

        if(!isValid(x, y, m, n)) return false;
        if(v[x][y]) return false;
        if(board[x][y] != word[index]) return false;

        v[x][y] = 1;

        for(auto& [dx, dy] : directions){
            int nx = x + dx;
            int ny = y + dy;

            if(bt(board, word, v, index+1, nx, ny, m, n, directions)) return true;
        }

        v[x][y] = 0;

        return false;
    }
};
