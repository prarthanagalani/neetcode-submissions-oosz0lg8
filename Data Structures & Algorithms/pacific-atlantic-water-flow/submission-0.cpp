class Solution {
public:
    
    void dfs(int i,int j, int ni, int nj,vector<vector<bool>>&vis,vector<vector<int>>&h){

        if(i < 0 || i >= h.size() || j < 0 || j >= h[0].size())
        return;

        if(vis[i][j]) return;

        if(ni >= 0 && nj >= 0 && h[i][j] < h[ni][nj]) return;

        vis[i][j] = true;

        dfs(i+1,j,i,j,vis,h);
        dfs(i,j+1,i,j,vis,h);
        dfs(i-1,j,i,j,vis,h);
        dfs(i,j-1,i,j,vis,h);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>ans;

        vector<vector<bool>>pac(n,vector<bool>(m)); //vis array
        vector<vector<bool>>atl(n,vector<bool>(m));

        // 1st col - pacific , last col - atlantic
        for(int i=0;i<n;i++){
            dfs(i,0,-1,-1,pac,heights);
            dfs(i,m-1,-1,-1,atl,heights);
        }

        // 1st row - pacific, last row - atlantic
        for(int i=0;i<m;i++){
            dfs(0,i,-1,-1,pac,heights);
            dfs(n-1,i,-1,-1,atl,heights);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j])
                ans.push_back({i,j});
            }
        }

        return ans;
    }
};