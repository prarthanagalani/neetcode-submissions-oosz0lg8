class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int>st;
        unordered_map<int,bool>mp;

        for(auto it : nums)
        st.insert(it);

        int mxLen = 0;

        for(int i=0;i<nums.size();i++){

            int cur = nums[i];
            mp[cur] = true;
            
            // cur can be start of my sequence
            if(st.count(cur-1) == 0){

                int len = 1;
                cur = cur + 1;

                while(st.count(cur) > 0){
                    mp[cur] = true;
                    len++;
                    cur++; 
                }

                mxLen = max(mxLen,len);

            }
            else if(mp[cur] == true)
            continue;
        }

        return mxLen;
        
    }
};
