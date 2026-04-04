class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        int n = t.size();

        stack<int>st;

        st.push(n-1);

        vector<int>ans(n,0);

        for(int i=n-2;i>=0;i--){

            int cur = t[i];

            int day = 0;

            while(!st.empty()){

                int temp = st.top();

                if(t[temp] > cur){
                    ans[i] = (temp - i);
                    st.push(i);
                    break;
                }
                else{
                    st.pop();
                }
            }

            if(st.empty()) st.push(i);
        }

        return ans;


        
    }
};
