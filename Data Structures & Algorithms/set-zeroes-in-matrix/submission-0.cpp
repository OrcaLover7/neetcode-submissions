class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;

        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto r : row) for(int j = 0; j < n; j++) matrix[r][j] = 0;

        for(auto c : col) for(int i = 0; i < m; i++) matrix[i][c] = 0;

        return;
    }
};
