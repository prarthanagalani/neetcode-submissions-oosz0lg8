class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            int cur = nums[i];
            int need = target - cur;

            if(mp.find(need) != mp.end()){

                return {mp[need],i};
            }
            
            mp[cur] = i;
        }

        return {-1,-1};
        
    }
};
