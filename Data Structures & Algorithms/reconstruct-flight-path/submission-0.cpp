class Solution {
public:
    
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mp;
    vector<string>ans;
 
    void dfs(string s)
    {
        auto &edges = mp[s];
        
        while(!edges.empty())
        {
            string s1 = edges.top();
            edges.pop();
            dfs(s1);
        }
        
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &i : tickets)
        {
            mp[i[0]].push(i[1]);
        }
        
        dfs("JFK");
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
       
    }
};