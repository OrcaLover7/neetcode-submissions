class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(bt(board, word, 0, i, j, m, n, dir)) return true;
                }
            }
        }

        return false;
    }

    bool bt(vector<vector<char>>& board, string& word, int index,int x, int y, int m, int n, vector<pair<int, int>>& dir){
        if(index == (int)word.size()){
            return true;
        }

        if(!isValid(x, y, m, n)) return false;

        if(board[x][y] == '#') return false;

        if(word[index] != board[x][y]) return false;
        char temp = board[x][y];

        board[x][y] = '#';

        for(auto& [dx, dy] : dir){
            int nx = x + dx;
            int ny = y + dy;
            if(bt(board, word, index+1, nx, ny, m, n, dir)) return true;
        }

        board[x][y] = temp;

        return false;
    }
};
