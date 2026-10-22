class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int zero = -1, last = -1;
        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero = i;
            if (nums[i] == n - 1) last = i;

            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n)
                inc = false;

            if (next != (nums[i] - 1 + n) % n)
                dec = false;
        }

        if (inc) {
            return min(zero, n - zero + 2);
        }

        if (dec) {
            return min(last + 1, n - zero);
        }

        return -1;
    }

    int minOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        return solve(nums);
    }
};