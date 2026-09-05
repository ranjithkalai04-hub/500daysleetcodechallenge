class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       
        int n=nums.size();
        int cnt=n;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                nums[i]='_';
               cnt--;
            }
        }
         sort(nums.begin(),nums.end());
        return cnt;
    }
};