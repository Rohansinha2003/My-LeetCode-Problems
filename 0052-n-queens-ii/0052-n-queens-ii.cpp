class Solution {
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int i = row, j = col;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        row=i;
        col=j;
        while (col >= 0 && row>=0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row--;
        }

        row=i;
        col=j;
        while (col >= 0 && row<n) {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }
        return true;

    }

    void nQueen(int n, int col, vector<string>& board, int& ans) {
        if (col == n) {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                nQueen(n, col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        nQueen(n, 0, board, ans);
        return ans;
    }
};