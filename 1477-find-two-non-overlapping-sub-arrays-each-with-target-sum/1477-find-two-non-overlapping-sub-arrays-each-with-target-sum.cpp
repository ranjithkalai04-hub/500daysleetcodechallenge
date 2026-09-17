class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int const inf=1e9;
        vector<int>dp(n+1,inf);
        int left=0;
        int sum =0;
        int ans=inf;
        for(int right=0;right<n;right++)
        {
            sum+=arr[right];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int len=right-left+1;
                if(arr[left]!=inf){
                    ans=min(ans,len+dp[left]);
                }
                dp[right+1]=min(dp[right],len);
            }
            else{
                dp[right+1]=dp[right];
            }
        }
        return ans==inf?-1:ans;
    }
};
/*they only acept o(n) so use sliding window concept and prefix sum dp
dp cus we need to return the min lenght of subarrays whose sum is equal to target
*/