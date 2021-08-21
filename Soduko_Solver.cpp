
  class Solution {

  private:

    bool helper(vector<vector<char>>& board){

      //Iterate over all board
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
               //if grid is filled with '.'
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                     // Check whether "c" is valid character to fill that grid  
                        if(isValid(board, i, j, c)){
                           // if "c" is valid then put 'c' at board[i][j]
                           // and call the recursion
                            board[i][j] = c;
                            if(helper(board)){
                               return true;
                            }
                            else{
                              // if 'c' is found not valid in future then 
                              // again put '.' at board[i][j] 
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    


    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c)return false;
            if(board[row][i] == c)return false;
            
            // 3*(row/3) + (i/3) == r , 3*(col/3) + (i%3)] == c 
            // is used to iterate in 3x3 matrix
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c)return false;
        }
        return true;
    }


public:

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};






