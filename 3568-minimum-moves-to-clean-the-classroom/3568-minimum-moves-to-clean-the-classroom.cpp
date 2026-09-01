class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        // Find rows and columns
        int m = classroom.size();
        int n = classroom[0].size();

        // Starting position
        int x = 0;
        int y = 0;

        // Number of litter
        int cnt = 0;

        // Number each litter
        vector<vector<int>> d(m, vector<int>(n, 0));

        // Find S and L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    x = i;
                    y = j;
                }

                if (classroom[i][j] == 'L') {
                    d[i][j] = cnt;
                    cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0) {
            return 0;
        }

        // visited[row][column][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        // BFS queue
        // (row, column, energy, mask)
        queue<tuple<int, int, int, int>> q;

        // Initially all litter is remaining
        int startMask = (1 << cnt) - 1;

        // Put starting state
        q.emplace(x, y, energy, startMask);

        // Mark starting state visited
        vis[x][y][energy][startMask] = true;

        // 4 directions
        vector<int> dirs = {-1, 0, 1, 0, -1};

        // Number of moves
        int ans = 0;

        // BFS
        while (!q.empty()) {

            // Number of states at this level
            int sz = q.size();

            while (sz--) {

                // Get current state
                auto [i, j, cur_energy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0) {
                    return ans;
                }

                // No energy
                if (cur_energy <= 0) {
                    continue;
                }

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nx = i + dirs[k];
                    int ny = j + dirs[k + 1];

                    // Valid cell and not a wall
                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        classroom[nx][ny] != 'X') {

                        // Calculate new energy
                        int nxt_energy;

                        if (classroom[nx][ny] == 'R') {
                            nxt_energy = energy;
                        }
                        else {
                            nxt_energy = cur_energy - 1;
                        }

                        // Copy current mask
                        int nxt_mask = mask;

                        // Collect litter
                        if (classroom[nx][ny] == 'L') {
                            nxt_mask &= ~(1 << d[nx][ny]);
                        }

                        // If state is not visited
                        if (!vis[nx][ny][nxt_energy][nxt_mask]) {

                            // Mark visited
                            vis[nx][ny][nxt_energy][nxt_mask] = true;

                            // Add to queue
                            q.emplace(
                                nx,
                                ny,
                                nxt_energy,
                                nxt_mask
                            );
                        }
                    }
                }
            }

            // Move to next BFS level
            ans++;
        }

        // Impossible
        return -1;
    }
};