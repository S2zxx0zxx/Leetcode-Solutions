class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2*n, false), diag2(2*n, false);
        backtrack(0, n, board, cols, diag1, diag2, result);
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) continue;
            
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;
            board[row][col] = 'Q';
            backtrack(row + 1, n, board, cols, diag1, diag2, result);
            board[row][col] = '.';
            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }
};