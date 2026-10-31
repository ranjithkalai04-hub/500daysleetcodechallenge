class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][0] = ways arriving from left (moving right)
        // dp[i][j][1] = ways arriving from above (moving down)

        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(n + 1, vector<int>(2, 0))
        );

        // One initial path at the starting cell
        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int fromRight = dp[i][j][0];
                int fromDown = dp[i][j][1];

                if (grid[i][j] == 0) {

                    // Normal cell
                    int total = (fromRight + fromDown) % MOD;

                    // Move right
                    dp[i][j + 1][0] =
                        (dp[i][j + 1][0] + total) % MOD;

                    // Move down
                    dp[i + 1][j][1] =
                        (dp[i + 1][j][1] + total) % MOD;

                } 
                else {

                    // Mirror: right becomes down
                    dp[i + 1][j][1] =
                        (dp[i + 1][j][1] + fromRight) % MOD;

                    // Mirror: down becomes right
                    dp[i][j + 1][0] =
                        (dp[i][j + 1][0] + fromDown) % MOD;
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};