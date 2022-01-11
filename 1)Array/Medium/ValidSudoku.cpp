7) 36. Valid Sudoku
/* Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules. */

TC-> O(N^2)
SC->O(N)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            { if(board[i][j]!='.')
            {   string row=to_string(board[i][j]).append(" row ").append(to_string(i));
                string col=to_string(board[i][j]).append(" col ").append(to_string(j));
                string box=to_string(board[i][j]).append(" box ").append(to_string(i/3)).append(to_string(j/3));
                // if((!s.insert(row)) || (!s.insert(col)) ||(!s.insert(box)) )
                //      return false;
              if(s.count(row) || s.count(col) || s.count(box))
                  return false;
              s.insert(row);
             s.insert(col);
             s.insert(box);
            }}
        }
        return true;
    }
};