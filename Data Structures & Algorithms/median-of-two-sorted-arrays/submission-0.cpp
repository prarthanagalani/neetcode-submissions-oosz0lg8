class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int left = (n1+n2+1)/2;

        int n = n1 + n2;

        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);

        int low = 0, high = n1;

        while(low <= high){
            int mid = (low + high) >> 1;

            int mid1 = left - mid;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid < n1)
            r1 = nums1[mid];

            if(mid1 < n2)
            r2 = nums2[mid1];

            if(mid-1 >= 0)
            l1 = nums1[mid-1];

            if(mid1-1 >=0)
            l2 = nums2[mid1-1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2==0){
                    double med = (max(l1,l2) + min(r1,r2)) / 2.0;
                    return med;
                }

                return (double)max(l1,l2);
            }
            else if(l1 > r2)
            high = mid - 1;
            else
            low = mid + 1;
        }

        return 0;
        
    }
};