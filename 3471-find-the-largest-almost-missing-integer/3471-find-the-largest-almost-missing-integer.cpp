class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,set<int>>freq;
        int n=nums.size();
        for(int i=0;i<=n-k;i++)
        {
            for(int j=i;j<i+k;j++){
                freq[nums[j]].insert(i);
            }
        }
        int maxi=-1;
        for(auto &[el,f] :freq){
            if(f.size()==1){
                maxi=max(maxi,el);
            }
        }
        return maxi;
    }
}; 
