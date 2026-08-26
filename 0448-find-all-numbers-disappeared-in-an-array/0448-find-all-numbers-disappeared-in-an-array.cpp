class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int x:nums){
            int index= abs(x)-1;
            nums[index]=-abs(nums[index]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};