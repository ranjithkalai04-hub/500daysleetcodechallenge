
class Solution {
    static constexpr long long MOD = 1000000007LL;

    vector<long long> sum, sumSq, lazy;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long add = val % MOD;

        sumSq[node] = (
            sumSq[node] + 2LL * add % MOD * sum[node] % MOD
            + len % MOD * add % MOD * add % MOD
        ) % MOD;

        sum[node] = (sum[node] + len % MOD * add) % MOD;
        lazy[node] = (lazy[node] + add) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sumSq[node] = (sumSq[node * 2] + sumSq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastSeen;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (lastSeen.count(nums[i]))
                prev = lastSeen[nums[i]];

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + sumSq[1]) % MOD;

            lastSeen[nums[i]] = i;
        }

        return static_cast<int>(ans);
    }
};

