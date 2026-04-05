class Solution {
public:
    
    void dfs(int idx, vector<int>&temp,vector<vector<int>>&ans,int target,vector<int>&nums){

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        

        if(idx == nums.size()) return;

        if(target >= nums[idx]){

            temp.push_back(nums[idx]);
            dfs(idx,temp,ans,target-nums[idx],nums);
            temp.pop_back();
        }

        dfs(idx+1,temp,ans,target,nums);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>>ans;

        vector<int>temp;

        dfs(0,temp,ans,target,nums);

        return ans;
        
    }
};
