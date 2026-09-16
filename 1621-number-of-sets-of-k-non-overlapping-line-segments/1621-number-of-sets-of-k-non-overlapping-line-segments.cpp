class Solution {
public:
    int numberOfSets(int n, int k) {
        int mod=1000000007;
        int N=n+k-1;
        int r=2*k;
        vector<vector<long long>> dp(N + 1, vector<long long>(r + 1, 0));

        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=min(i,r);j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        return dp[N][r];
    }
};