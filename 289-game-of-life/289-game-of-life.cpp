class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count=0;
                
                //check for top row elements
                if(i>0 && j>0 && board[i-1][j-1]>=1) count++; //top left
                if(j>0 && board[i][j-1]>=1) count++; //top
                if(i<n-1 && j>0 && board[i+1][j-1]>=1) count++; //top right
                
                //check for current row elemnents 
                if(i>0 && board[i-1][j]>=1) count++; //left
                if(i<n-1 && board[i+1][j]>=1) count++; //right
                
                //check for down row elemnents 
                if(i>0 && j<m-1 && board[i-1][j+1]>=1) count++; //down left
                if(j<m-1 && board[i][j+1]>=1) count++; //down
                if(i<n-1 && j<m-1 && board[i+1][j+1]>=1) count++; //down right

                if(board[i][j]==1 && (count<2 || count>3)) board[i][j]=2;
                if(board[i][j]==0 && count==3) board[i][j]=-2;
                
            }
        }
         for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==2) board[i][j]=0;
                if(board[i][j]==-2) board[i][j]=1;
            }
        }
           
    }
};