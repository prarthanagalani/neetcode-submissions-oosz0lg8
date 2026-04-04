class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        int i=0,j=n-1;

        while(i < j){

            if(nums[i] == target - nums[j])
            return {i+1,j+1};

            else if(nums[i] > target - nums[j])
            j--;

            else
            i++;

        }

        return {-1,-1};


        
    }
};
