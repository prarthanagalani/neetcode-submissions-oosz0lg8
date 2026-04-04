class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>mp;

        for(auto it : strs){
            string cur = it;

            vector<int>freq(26,0);

            for(auto ch : cur)
            freq[ch-'a']++;

            string key = to_string(freq[0]);
            for(int i=1;i<26;i++)
            key += ',' + to_string(freq[i]);

            mp[key].push_back(cur);
        }

        vector<vector<string>>ans;

        for(auto it : mp)
        ans.push_back(it.second);

        return ans;
        
    }
};
