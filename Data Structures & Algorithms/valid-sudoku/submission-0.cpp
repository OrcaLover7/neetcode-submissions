class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char curr = board[i][j];
                if(curr == '.') continue;
                //for row
                if(rows[i].count(curr)) return false;
                rows[i].insert(curr);

                //for col
                if(cols[j].count(curr)) return false;
                cols[j].insert(curr);


                //for box
                int a = i/3, b = j/3;
                int box_index = a*3 + b;
                if(boxes[box_index].count(curr)) return false;
                boxes[box_index].insert(curr);
            }
        }
        return true;
    }
};
