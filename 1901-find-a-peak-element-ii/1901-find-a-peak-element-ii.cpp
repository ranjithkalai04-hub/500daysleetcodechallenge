class Solution {
public:
int maxele(vector<vector<int>>& mat,int m,int n,int col){
    int maxi=-1;
    int index=-1;
    for(int i=0;i<m;i++){
        if(mat[i][col]>maxi){
            maxi=mat[i][col];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low =0;
        int high =n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row =maxele(mat,m,n,mid);
            int left=(mid-1)>=0?mat[row][mid-1]:-1;
            int right = (mid+1)<n?mat[row][mid+1]:-1;
            if(mat[row][mid]>right && mat[row][mid]>left){
                return {row,mid};
            }
            else if (mat[row][mid]<left){
                high=mid-1;
            }
            else{
                low =mid+1;
            }

        }
        return {-1,-1};
    }
};