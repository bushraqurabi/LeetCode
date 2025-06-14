class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }

private:
    bool isSafe(const vector<string>& board, int row, int col, int n) {
        
        for (int j = 0; j < col; ++j) {
            if (board[row][j] == 'Q')
                return false;
        }

        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }

        
        for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& result, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';            //  DO
                solve(col + 1, board, result, n); //  RECURSE
                board[row][col] = '.';            //  UNDO
            }
        }
    }
};
