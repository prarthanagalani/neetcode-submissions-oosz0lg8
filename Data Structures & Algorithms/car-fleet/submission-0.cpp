class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {


        int n = p.size();

        vector<pair<int,int>>v;

        for(int i=0;i<n;i++)
        v.push_back({p[i],s[i]});

        sort(v.rbegin(),v.rend());

        int fleets = 1;

        double prev = (double)(t - v[0].first)/v[0].second;

        for(int i=1;i<n;i++){
            double cur = (double)(t - v[i].first)/v[i].second;

            if(cur > prev)
            { 
                fleets++;
                prev = cur;

            }
        }

        return fleets;
        
    }
};
