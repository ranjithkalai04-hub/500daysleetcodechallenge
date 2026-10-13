class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long  score =0;
        int n=nums.size();
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=nums[i]*nums[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n/2;i++){
            score-=arr[i];

        }
          for(int i=n/2;i<n;i++){
            score+=arr[i];
            
        }
        return score;
    }
};