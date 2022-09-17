class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string temp(n, '.');
        for(int i=0; i<n; i++)
            board[i] = temp;
        help(0, n, ans, board);
        return ans;
    }
    
    void help(int col, int n, vector<vector<string>> &ans, vector<string> &board){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(safe(row, col, board, n)){
                board[row][col] = 'Q';
                help(col+1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }
    
    bool safe(int row, int col, vector<string> board, int n){
         int duprow = row;
         int dupcol = col;

         while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            row--;
            col--;
          }

          col = dupcol;
          row = duprow;
          while (col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            col--;
          }

          row = duprow;
          col = dupcol;
          while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
              return false;
            row++;
            col--;
          }
          return true;
    }
};