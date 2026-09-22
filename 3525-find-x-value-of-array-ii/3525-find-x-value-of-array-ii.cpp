class Solution {
public:

    struct Node {
        int prod = 1;
        array<int, 5> cnt{};

        Node() {
            cnt.fill(0);
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node &A, Node &B) {

        Node C;

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] += A.cnt[r];
        }

        // Prefixes that continue from A into B
        for (int r = 0; r < k; r++) {

            int newRemainder = (A.prod * r) % k;

            C.cnt[newRemainder] += B.cnt[r];
        }

        // Product of the complete segment
        C.prod = (A.prod * B.prod) % k;

        return C;
    }

    Node makeNode(int value) {

        Node node;

        node.prod = value % k;

        node.cnt[node.prod] = 1;

        return node;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);

        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            tree[node] = makeNode(value);
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {

            update(node * 2,
                   l,
                   mid,
                   index,
                   value);
        }
        else {

            update(node * 2 + 1,
                   mid + 1,
                   r,
                   index,
                   value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely on left
        if (qr <= mid) {
            return query(node * 2,
                         l,
                         mid,
                         ql,
                         qr);
        }

        // Completely on right
        if (ql > mid) {
            return query(node * 2 + 1,
                         mid + 1,
                         r,
                         ql,
                         qr);
        }

        // Query both sides
        Node leftPart =
            query(node * 2,
                  l,
                  mid,
                  ql,
                  qr);

        Node rightPart =
            query(node * 2 + 1,
                  mid + 1,
                  r,
                  ql,
                  qr);

        return merge(leftPart, rightPart);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists for future queries
            nums[index] = value;

            update(1,
                   0,
                   n - 1,
                   index,
                   value);

            // We need all subarrays starting at start.
            Node res =
                query(1,
                      0,
                      n - 1,
                      start,
                      n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};