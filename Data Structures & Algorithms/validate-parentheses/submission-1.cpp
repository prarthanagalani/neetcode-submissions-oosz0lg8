class Solution {
public:
    bool isValid(string s) {

        int n = s.length();

        if(n == 0 || n == 1) return false;

        stack<char>st;

        for(int i=0;i<n;i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }

            else{

                if(st.empty()) return false;

                char ch = st.top();

                if(s[i] == ')' && ch == '(')
                st.pop();

                else if(s[i] == '}' && ch == '{')
                st.pop();

                else if(s[i] == ']' && ch == '[')
                st.pop();

                else
                return false;
            }
        }
         
        if(st.empty()) return true;
        return false;
        
    }
};
