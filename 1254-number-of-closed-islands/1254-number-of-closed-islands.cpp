class Solution {
public:

    void bfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<bool>>& vis,int m,int n){

        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                  if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
            }
        }
    }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int r=0;r<m;r++){
            if(grid[r][0]==0 && !(vis[r][0])){
                bfs(r,0,grid,vis,m,n);
            }
            if(grid[r][n-1]==0 && !(vis[r][n-1])){
                bfs(r,n-1,grid,vis,m,n);
            }
        }
        for(int c=0;c<n;c++){
            if(grid[0][c]==0 && !(vis[0][c])){
                bfs(0,c,grid,vis,m,n);
            }
            if(grid[m-1][c]==0 && !(vis[m-1][c])){
                bfs(m-1,c,grid,vis,m,n);
            }
        }
        int cnt =0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0 && !vis[r][c]){
                    cnt++;
                    bfs(r,c,grid,vis,m,n);
                }
                
            }
             
        }
       return cnt;
    
    }
    
};