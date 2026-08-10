class Solution {
public:
    bool possible(vector<int>& b,int days,int m, int k){
        int n=b.size();
        int cnt=0;int nofb=0;
        for(int i=0;i<n;i++){
            if(b[i]<=days){
                cnt++;
            }
            else{
                nofb+=(cnt/k);
                cnt=0;
            }
        }
        nofb+=(cnt/k);
        return nofb>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        int mini=INT_MAX;int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,b[i]);
            maxi=max(maxi,b[i]);
        }
        int low=mini;int high =maxi;
        if(1ll*m*k>n)return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(b,mid,m,k)){
                high=mid-1;   
            }
            else
            low=mid+1;
        }
        return low;
    }
};