class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        bool row_zero = false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if(i > 0) matrix[i][0] = 0;
                    else row_zero = true;
                }
            }
        }

        for(int i = 1; i < m; i++) for(int j = 1; j < n; j++) if(matrix[0][j] == 0 or matrix[i][0] == 0) matrix[i][j] = 0;

        if(matrix[0][0] == 0) for(int i = 0; i < m; i++) matrix[i][0] = 0; 
        if(row_zero) for(int j = 0; j < n; j++) matrix[0][j] = 0;

        return;
    }
};
