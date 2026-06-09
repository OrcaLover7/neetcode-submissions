class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), box(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char curr = board[i][j];
                if(curr == '.') continue;

                if(row[i].count(curr)) return false;
                row[i].insert(curr);

                if(col[j].count(curr)) return false;
                col[j].insert(curr);

                int box_index = (i/3)*3 + (j/3);
                if(box[box_index].count(curr)) return false;
                box[box_index].insert(curr);
            }
        }

        return true;
    }
};
