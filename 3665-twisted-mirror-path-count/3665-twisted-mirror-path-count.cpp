
class Solution {
public:
    const int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // memo[i][j][d] stores the final destination
        // after entering mirror (i,j) in direction d.
        // -2 = not calculated, -1 = invalid.
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );

        // direction 0 = right
        // direction 1 = down

        function<int(int,int,int)> resolve =
        [&](int i, int j, int dir) -> int {

            if(i < 0 || i >= m || j < 0 || j >= n) {
                return -1;
            }

            if(memo[i][j][dir] != -2) {
                return memo[i][j][dir];
            }

            int ni, nj;

            if(dir == 0) {
                ni = i + 1;
                nj = j;
            }
            else {
                ni = i;
                nj = j + 1;
            }

            // Check boundaries
            if(ni >= m || nj >= n) {
                return memo[i][j][dir] = -1;
            }

            // Empty cell: robot stops reflecting
            if(grid[ni][nj] == 0) {
                return memo[i][j][dir] = ni * n + nj;
            }

            // Mirror: reflect again
            return memo[i][j][dir] =
                resolve(ni, nj, 1 - dir);
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        // Process cells in row-major order
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 || dp[i][j] == 0) {
                    continue;
                }

                // Move right
                if(j + 1 < n) {

                    int dest;

                    if(grid[i][j+1] == 0) {
                        dest = i * n + (j+1);
                    }
                    else {
                        dest = resolve(i, j+1, 0);
                    }

                    if(dest != -1) {
                        int r = dest / n;
                        int c = dest % n;

                        dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                    }
                }

                // Move down
                if(i + 1 < m) {

                    int dest;

                    if(grid[i+1][j] == 0) {
                        dest = (i+1) * n + j;
                    }
                    else {
                        dest = resolve(i+1, j, 1);
                    }

                    if(dest != -1) {
                        int r = dest / n;
                        int c = dest % n;

                        dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};
