class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        vector<int> ans;
       int n=nums.size();
       int sm=nums[0];
       int lg=nums[n-1];
       int j=0;
       for(int i=sm;i<=lg;i++){
        if(i==nums[j])j++;
        else ans.push_back(i);
       }
       return ans;
    }
};