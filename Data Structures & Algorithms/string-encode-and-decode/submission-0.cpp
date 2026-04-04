class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";

        for(auto it : strs)
        {
            ans += it;
            ans += "-";
        }

        return ans;



    }

    vector<string> decode(string s) {

        vector<string>ans = split_string(s,'-');

        return ans;

    }

   vector<string> split_string(string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    // Use getline to extract characters from the stream into 'token' until the delimiter is found
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
};
