class Solution {
public:
    int evalRPN(vector<string>& s) {

        int n = s.size();

        stack<int>st;

        for(int i=0;i<n;i++){

            if(s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/"){

                int op2 = st.top();
                st.pop();

                int op1 = st.top();
                st.pop();

                if(s[i] == "+")
                st.push(op1 + op2);

                else if(s[i] == "*")
                st.push(op1 * op2);

                else if(s[i] == "-")
                st.push(op1 - op2);

                else
                st.push(op1 / op2);
            }
            else
            st.push(stoi(s[i]));
        }

        return st.top();
        
    }
};
