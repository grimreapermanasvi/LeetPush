class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>seen;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;

                string num=string(1, board[i][j]);

                if(seen.count(num+"r"+ to_string(i)) ||
                seen.count(num+"c"+to_string(j))||
                seen.count(num + "b" + to_string(i/3) + to_string(j/3))) {
                    return false;
                }

                seen.insert(num + "r" + to_string(i));
                seen.insert(num + "c" + to_string(j));
                seen.insert(num + "b" + to_string(i/3) + to_string(j/3));
            }
        }
        return true;
    }
};