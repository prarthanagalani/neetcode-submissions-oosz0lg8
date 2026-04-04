class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        unordered_map<char,int>mp;

        int mx_freq = 0;

        int i=0,j=0;

        int ans = 0;

        for(i=0;i<n;i++){

            mp[s[i]]++;
            mx_freq = max(mx_freq,mp[s[i]]);

            if(i-j+1 > mx_freq+k){
                mp[s[j]]--;
                j++;
            }
            else
            {
                ans = max(ans,i-j+1);
            }
        }

        ans = max(ans,i-j+1);

        return ans-1;
        
    }
};
