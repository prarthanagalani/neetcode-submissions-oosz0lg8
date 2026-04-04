class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
    int n = arr.size();
        
    sort(arr.begin(),arr.end());
    
    vector<vector<int>>ans;
    
    for(int i=0;i<=n-3;i++)
    {
       // int x = arr[i];
        
        int s = i+1,e = n-1;
        
        while(s < e)
        {
            if(arr[i] + arr[s] + arr[e] == 0)
            {
                vector<int>v = {arr[i],arr[s],arr[e]};
                ans.push_back(v);
                
                int x  = arr[s];
                int y  = arr[e];
                
                while(s < e && arr[s] == x)
                {
                    s++;
                }
                
                while(s<e && arr[e] == y)
                {
                    e--;
                }
            }
            
            else if(arr[i] + arr[s] + arr[e] > 0)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        
        while(i+1 < n && arr[i] == arr[i+1])
        {
            i++;
        }
        
    }
    
    return ans;
        
    }


};