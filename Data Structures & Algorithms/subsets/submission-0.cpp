class Solution {
public:
    void dfs(int idx, vector<int>&temp, vector<vector<int>>&ans,vector<int>&nums){

        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        dfs(idx+1,temp,ans,nums);

        temp.pop_back();
        dfs(idx+1,temp,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>temp;

        dfs(0,temp,ans,nums);

        return ans;
        
    }
};
