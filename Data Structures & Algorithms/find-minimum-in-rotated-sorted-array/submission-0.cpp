class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();

        int low = 0, high = n-1;

        int mn = INT_MAX;

        while(low <= high){

            int mid = (low + high)/2;

            mn = min({mn,nums[mid],nums[low],nums[high]});

            if(nums[mid] > nums[low] && nums[mid] > nums[high]){
                low = mid + 1;
            }
            else
            high = mid-1;
        }
        
        return mn;
    }
};
