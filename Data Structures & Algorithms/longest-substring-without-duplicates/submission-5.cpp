class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        if(n == 0 || n == 1)
        return n;

        vector<int>hash(256,-1);

        int mxlen = 0;

        int l=0,r=0;

        while(r < n){

            if(hash[s[r]] != -1){

                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            hash[s[r]] = r;

            mxlen = max(mxlen,r-l+1);
            r++;
        }

        return mxlen;
        
    }
};
