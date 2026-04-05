class Solution {
public:
    void dfs(int idx, vector<int>&temp, vector<vector<int>>&v, int target, vector<int>&nums){

        if(target == 0){
            v.push_back(temp);
            return;
        }

        if(idx == nums.size()) return;

        for(int i=idx;i<nums.size();i++){
            if(i > idx && nums[i] == nums[i-1])
            continue;

            if(nums[i] > target) break;

            temp.push_back(nums[i]);
            dfs(i+1,temp,v,target-nums[i],nums);
            temp.pop_back();
        }

      //  dfs(idx+1,temp,v,target,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        vector<vector<int>>v;

        // unordered_set<vector<int>>s;

        sort(nums.begin(),nums.end());

        vector<int>temp;

        dfs(0,temp,v,target,nums);

        return v;
        
    }
};
