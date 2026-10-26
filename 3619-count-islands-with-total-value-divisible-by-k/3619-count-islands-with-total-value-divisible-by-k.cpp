class Solution {
public:
      long long dfs(int r, int c, vector<vector<int>>& grid,int m,int n) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 0) {
            return 0;
        }

        // Mark this cell as visited.
        int value = grid[r][c];
        grid[r][c] = 0;

        // Explore all 4 directions.
        long long sum = value;

        sum += dfs(r + 1, c, grid,m,n);
        sum += dfs(r - 1, c, grid,m,n);
        sum += dfs(r, c + 1, grid,m,n);
        sum += dfs(r, c - 1, grid,m,n);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
       int m=grid.size();
       int n=grid[0].size();

       
        int ans = 0;
       for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            if(grid[r][c]>0 ){
                long long sum=dfs(r,c,grid,m,n);
                if (sum % k == 0) 
                        ans++;
            }
             
                    
        }
       }
return ans;
    }
};