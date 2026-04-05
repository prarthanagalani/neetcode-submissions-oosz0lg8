class Solution {
public:
    
    void f(int idx,int n,vector<int>&arr,vector<int>&v,vector<vector<int>>&ans)
{
    ans.push_back(v);
    
    for(int i = idx;i<n;i++)
    {
        if(i != idx && arr[i] == arr[i-1])
        {
            continue;
        }
        
        v.push_back(arr[i]);
        
        f(i+1,n,arr,v,ans);
        v.pop_back();
        
    }
}

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<vector<int>>ans;
    
    vector<int>v;
    
    sort(arr.begin(),arr.end());
    
    f(0,n,arr,v,ans);
    
    return ans;
        
       
        
    }
};