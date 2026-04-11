class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int findUPar(int node){
    if(node==parent[node]) return node;

    //path compression
    return parent[node]=findUPar(parent[node]);
  }

    void unionByRank(int u,int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);

    if(ulp_u==ulp_v) return;

    if(rank[ulp_u]<rank[ulp_v]){
      parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_v]<rank[ulp_u]){
      parent[ulp_v]=ulp_u;
    }
    else{
      parent[ulp_v]=ulp_u;
      rank[ulp_u]++;
    }
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = -1;

        for(auto it : edges){
            n = max(n,max(it[0],it[1]));
        }

        parent.resize(n+1,0);
        rank.resize(n+1,0);


        for(int i=1;i<=n;i++)
        parent[i] = i;

        for(auto it : edges){

            if(findUPar(it[0]) != findUPar(it[1])){
                unionByRank(it[0],it[1]);
            }
            else
            return {it[0],it[1]};
        }

        return {};
        
    }
};
