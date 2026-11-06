class Solution {
public:

    void findcombo(int ind, vector<vector<int>>& ans, vector<int>& ds,vector<int>& arr,int key)
    {
        int n=arr.size();
        if(ind==n){
            if(key==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=key){
            ds.push_back(arr[ind]);
            findcombo(ind,ans,ds,arr,key-arr[ind]);
            ds.pop_back();
        }
        findcombo(ind+1,ans,ds,arr,key);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        findcombo(0,ans,ds,candidates,target);
        return ans;
    }
};