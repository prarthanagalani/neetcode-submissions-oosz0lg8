class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";

        for(auto it : strs)
        {
            ans += to_string(it.length());
            ans += "#";
            ans += it;
        }

        return ans;



    }

    vector<string> decode(string s) {

        vector<string>ans;
        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            ans.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }

        return ans;

    }
};