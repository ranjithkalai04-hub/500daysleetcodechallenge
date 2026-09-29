class Solution {
public:

    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        int m = grid.size();
        int n = grid[0].size();

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (balance > m + n - 1)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = false;
        bool right = false;

        if (i + 1 < m)
            down = solve(grid, i + 1, j, balance);

        if (j + 1 < n)
            right = solve(grid, i, j + 1, balance);

        return dp[i][j][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));

        return solve(grid, 0, 0, 0);
    }
};

/*

    vector<vector<vector<int>>> dp;
    bool solve(vector<vector<char>>&grid, int i, int j, int balance){
         int m=grid.size();
         int n= grid[0].size();

         if(grid[i][j]=='('){
            balance++;
         }
         else {
            balance--;
         }

         if(balance<0){
            return false;
         }
         if(balance> m+n-1){
            return false;
         }
         if(i==m-1&&j==n-1){
            return balance==0;
         }
         if(dp[i][j][balance]!=-1){
            return dp[i][j][balance];
         }
         bool down= false;
         bool right= false;

         if(i+1<m){
            down= solve(grid, i+1, j, balance);
         }
         if(j+1<n){
            right= solve(grid, i, j+1, balance);
         }
         return dp[i][j][balance]= down || right;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
         int m = grid.size();
         int n= grid[0].size();

         if((m+n-1)%2==1){
            return false;
         }

         dp.assign(m, vector<vector<int>>(n, vector<int>(m+n-1)));

         return solve(grid,0,0,0);


        
    }
};*/