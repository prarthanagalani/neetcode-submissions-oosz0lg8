class Solution {
public:
    
    void dfs(int open, int close, string &output, vector<string>&ans,int n){

        if(open == n && close == n){
            ans.push_back(output);
            return;
        }

        if(open < n){
            output += '(';
            dfs(open+1,close,output,ans,n);
            output.pop_back();
        }
        if(close < open){
            output += ')';
            dfs(open,close+1,output,ans,n);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string>ans;

        string output = "";

        dfs(0,0,output,ans,n);

        return ans;

        
    }
};
