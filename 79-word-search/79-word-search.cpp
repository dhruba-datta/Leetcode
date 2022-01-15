class Solution {
public:
   bool exist(vector<vector<char>> &board, string word) {
       int row=board.size(), col=board[0].size();
       for(int i = 0 ; i < row ; ++i)
           for(int j = 0 ; j < col ; ++j)
               if(search(0 , i , j , board , word))
                   return true;
       return false;
   }
   bool search(int index , int x , int y , vector<vector<char>> &board , string &word)
   {
       if(index == word.size())
           return true;
       
       if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '.') 
           return false;
       
       if(board[x][y] != word[index])
           return false;
       
       char temp = board[x][y];
       board[x][y] = '.'; 
       if(search(index + 1 , x - 1 , y , board , word) || search(index + 1 , x + 1 , y , board , word) || search(index + 1 , x , y - 1 , board , word) || search(index + 1 , x , y + 1 , board , word))
           return true;
           
       board[x][y] = temp;
       return false;
       
   }
   
};