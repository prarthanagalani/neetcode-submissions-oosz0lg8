class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(int i,int j,vector<vector<char>>&grid, vector<vector<int>>&vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return;

        vis[i][j] = 1;

        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];

            if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size())
            continue;

            if(grid[new_x][new_y] == '1' && !vis[new_x][new_y])
            dfs(new_x,new_y,grid,vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
                
            }
        }

        return cnt;
    
    }
};