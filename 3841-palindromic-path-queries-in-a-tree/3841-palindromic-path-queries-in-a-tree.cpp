
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, parent, sz;
    vector<int> basePrefix, bit;
    int timer = 0;

    // Fenwick Tree XOR update
    void updateBIT(int i, int val) {
        for (; i < (int)bit.size(); i += i & -i) {
            bit[i] ^= val;
        }
    }

    // Fenwick Tree prefix XOR
    int queryBIT(int i) {
        int ans = 0;

        for (; i > 0; i -= i & -i) {
            ans ^= bit[i];
        }

        return ans;
    }

    // Range XOR update
    void rangeUpdate(int l, int r, int val) {
        updateBIT(l + 1, val);
        updateBIT(r + 2, val);
    }

    // Get current root-to-node XOR mask
    int getPrefix(int u) {
        return basePrefix[u] ^ queryBIT(tin[u] + 1);
    }

    // Lowest Common Ancestor
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        parent.assign(n, 0);
        sz.assign(n, 1);
        basePrefix.assign(n, 0);

        timer = 0;

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Calculate LOG
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        up.assign(LOG, vector<int>(n, 0));

        // Iterative DFS and Euler Tour
        vector<int> order;
        stack<int> st;

        st.push(0);

        parent[0] = 0;
        basePrefix[0] = 1 << (s[0] - 'a');

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = timer++;
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) {
                    continue;
                }

                parent[v] = u;
                depth[v] = depth[u] + 1;

                basePrefix[v] =
                    basePrefix[u] ^ (1 << (s[v] - 'a'));

                st.push(v);
            }
        }

        // Calculate subtree sizes
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        // Calculate subtree ending positions
        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + sz[u] - 1;
        }

        // Build binary lifting table
        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        // Initialize Fenwick Tree
        bit.assign(n + 2, 0);

        vector<bool> answer;

        // Process queries
        for (string &q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int diff = oldMask ^ newMask;

                // Update the subtree
                rangeUpdate(tin[u], tout[u], diff);

                s[u] = c;
            }
            else {
                int v;
                ss >> v;

                int lca = getLCA(u, v);

                int mask =
                    getPrefix(u) ^
                    getPrefix(v) ^
                    (1 << (s[lca] - 'a'));

                // Check if at most one odd frequency exists
                answer.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};
