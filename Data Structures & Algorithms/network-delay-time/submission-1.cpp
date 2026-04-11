class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n+1];

        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // distance, node
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;

        vector<int>dist(n+1,1e5);

        pq.push({0,k});

        dist[k] = 0;

        while(!pq.empty()){

            auto it  = pq.top();
            pq.pop();

            int cur_dist = it.first;
            int node = it.second;

            for(auto i : adj[node]){
                int new_node = i.first;
                int time = i.second;

                if(dist[new_node] > time + cur_dist){
                    dist[new_node] = time + cur_dist;
                    pq.push({time+cur_dist,new_node});
                } 
            }
        }

        int mn_time = 0;

        for(int i=1;i<=n;i++){
            if(dist[i] == 1e5) return -1;

            mn_time = max(mn_time,dist[i]);
        }

        return mn_time;


        
    }
};