class Solution {
    bool t[101][101][201];
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if((m+n-1)%2!=0)return false;

        if(grid[0][0]!='(' || grid[m-1][n-1]!=')'){
            return false;    
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                for(int opencnt=0;opencnt<=i+j+1;opencnt++){
                    if(i==m-1 && j==n-1){
                        t[i][j][opencnt]=(opencnt==0);
                        continue;
                    }
                    t[i][j][opencnt]=false;

                    if(i+1<m){
                        int newcnt=(grid[i+1][j]=='(')?opencnt+1:opencnt-1;
                        if(newcnt>=0 && t[i+1][j][newcnt]==true){
                            t[i][j][opencnt]=true;
                        }
                    }
                    
                    if(j+1<n){
                        int newcnt=(grid[i][j+1]=='(')?opencnt+1:opencnt-1;
                        if(newcnt>=0 && t[i][j+1][newcnt]==true){
                            t[i][j][opencnt]=true;
                        }
                    }
                }
            }
        }



        return t[0][0][1];


    }
};
/*
bal<0  => false
tar==0?true:false
memo
so down => update bal
go right => update bal
*/