class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool search(int idx, int row,int col,string &word,vector<vector<char>>&board){
        if(idx == word.size())
        return true;

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        return false;

        if(word[idx] == board[row][col]){
            board[row][col] = '#';

            for(int i=0;i<4;i++){
            int new_x = row+dx[i];
            int new_y = col+dy[i];

            if(search(idx+1,new_x,new_y,word,board))
            return true;
          }

          board[row][col] = word[idx];
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        //int idx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(search(0,i,j,word,board))
                    return true;
                }
            }
        }

        return false;
        
    }
};