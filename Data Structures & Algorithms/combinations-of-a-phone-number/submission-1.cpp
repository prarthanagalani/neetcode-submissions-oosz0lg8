class Solution {
public:
    void f(int idx,string &output, string &digits, string mp[],vector<string>&ans){

        if(idx == digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[idx] - '0';

        string cur = mp[number];

        for(int i=0;i<cur.length();i++){
            output += cur[i];
            f(idx+1,output,digits,mp,ans);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0) return {};

        vector<string>ans;

        string output = "";

        string mp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        f(0,output,digits,mp,ans);

        return ans;
        
    }
};