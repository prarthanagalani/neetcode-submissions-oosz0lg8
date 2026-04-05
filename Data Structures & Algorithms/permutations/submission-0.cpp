class Solution {
public:

    // tc -> n! x n
    // sc - > No algorithm space (only O(n) Auxiliary space)

    void f(int idx,vector<int>&nums,int n, vector<vector<int>>&ans){
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            f(idx+1,nums,n,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;

        int n = nums.size();

        f(0,nums,n,ans);

        return ans;
        
    }
};