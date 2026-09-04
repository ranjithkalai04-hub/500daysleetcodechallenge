class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int i,j;
        int n=nums.size();
        int maxi=INT_MIN;
        
        for(i=0;i<n;i++){
              maxi=max(maxi,nums[i]);
              int mini=INT_MAX;
        for(j=i;j<n;j++){    
            mini=min(mini,nums[j]);
        }
        if((maxi-mini)<=k){
            return i;
        }
      }
      return -1;
    }
};