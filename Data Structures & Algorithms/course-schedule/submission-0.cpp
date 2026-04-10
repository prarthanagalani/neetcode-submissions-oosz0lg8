class Solution {
public:
    
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis,vector<vector<int>>&adj){

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){

            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj) == true) return true;
            }
            else{

                if(pathVis[it]) return true;
            }

        }

        pathVis[node] = 0;

        return false;
    }
    bool canFinish(int V, vector<vector<int>>& p) {

        vector<int>vis(V,0);
        vector<int>pathVis(V,0);

        vector<vector<int>>adj(V);

        for(auto it : p){

             adj[it[1]].push_back(it[0]);

        }

        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,pathVis,adj) == true)
                return false;
            }
        }

        return true;

        
    }
};