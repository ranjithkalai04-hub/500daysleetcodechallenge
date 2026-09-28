class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cons=0;
        int ans=0;
       
    
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                cons++;
                ans=max(ans, cons);
            }
            if(nums[i]==0){
                cons=0;
            }
            
        } 

        return ans;
        
    }
};