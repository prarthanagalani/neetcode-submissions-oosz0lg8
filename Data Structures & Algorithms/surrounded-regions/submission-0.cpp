class Solution {
public:
    void solve(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 'O')
            {
                q.push({0,i});
                
            }

            if(grid[n-1][i] == 'O')
            {
                q.push({n-1,i});
            
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 'O')
            {
                q.push({i,0});
            }

            if(grid[i][m-1] == 'O')
            {
                q.push({i,m-1});
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            vis[row][col] = 1;

            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O')
                {
                    q.push({nrow,ncol});

                }
            }


        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 'O')
                {
                    grid[i][j] = 'X';
                }
            }
        }

      
 
        


    }
};