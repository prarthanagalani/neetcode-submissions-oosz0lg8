class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int>st;

        for(auto it : nums)
        st.insert(it);

        int mxLen = 0;

        for(int i=0;i<nums.size();i++){

            int cur = nums[i];
            
            // cur can be start of my sequence
            if(st.find(cur-1) == st.end()){

                int len = 1;
                cur = cur + 1;

                while(st.find(cur) != st.end()){
                    len++;
                    cur++; 
                }

                mxLen = max(mxLen,len);

            }
           
        }

        return mxLen;
        
    }
};
