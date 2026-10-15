class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<char> rows;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if( board[i][j] == '.' ) {
                    continue;
                } else {
                    if( rows.contains(board[i][j]) ) {
                        return false;
                    } else {
                        rows.insert( board[i][j] );
                    }
                }
            }
            rows.clear();
        }

        unordered_set<char> columns;
        for( int i = 0; i < board.size(); i++ ) {
            for( int j = 0; j < board.size(); j++ ) {
                if( board[j][i] == '.' ) {
                    continue;
                } else {
                    if( columns.contains(board[j][i]) ) {
                        return false;
                    } else {
                        columns.insert( board[j][i] );
                    }
                }
            }
            columns.clear();
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
