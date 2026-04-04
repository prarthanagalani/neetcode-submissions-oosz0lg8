class Solution {
public:
    int f(int cur,vector<int>&piles){

        long totalhours = 0;

        for(int i=0;i<piles.size();i++){

            totalhours += ceil((double)piles[i]/(double)cur);
        }

        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

       int mx = *max_element(piles.begin(),piles.end());

        int low = 1,high = mx;
        int ans = mx;

        while(low <= high){
            int mid = (low + high)/2;

            int totalhours = f(mid,piles);

            if(totalhours <= h && totalhours > 0)
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};