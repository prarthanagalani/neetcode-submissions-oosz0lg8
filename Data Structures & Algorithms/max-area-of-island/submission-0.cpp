class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        int ans = 0;

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt = 0;
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                }

                while(!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                   
                    cnt++;


                    for(int k=0;k<4;k++)
                    {
                        int nrow = row + drow[k];
                        int ncol = col + dcol[k];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                        {
                            q.push({nrow,ncol});
                             vis[nrow][ncol] = 1;

                        }
                    }
                }

                ans = max(ans,cnt);


            }
        }

        return ans;
        
    }
};