
class Solution {
public:
    static const int MOD = 1'000'000'007;
    vector<vector<long long>> comb;

    int solve(vector<int>& nums) {
        int n = nums.size();

        // Base case: an empty or single-node tree
        if (n <= 2) {
            return 1;
        }

        int root = nums[0];

        vector<int> left, right;

        // Divide elements into left and right subtrees
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        // Count valid reorderings of each subtree
        long long leftWays = solve(left);
        long long rightWays = solve(right);

        int L = left.size();
        int R = right.size();

        // Choose positions for the left subtree elements
        long long ways = comb[L + R][L];

        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute combinations using Pascal's triangle
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] +
                     comb[i - 1][j]) % MOD;
            }
        }

        // Subtract the original ordering
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
