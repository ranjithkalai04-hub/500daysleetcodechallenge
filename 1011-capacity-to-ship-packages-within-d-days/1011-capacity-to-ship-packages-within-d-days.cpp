class Solution {
public:
int nod(vector<int>w,int cap){
    int days=1;
    int load=0;
    for(int i=0;i<w.size();i++){
        if(load+w[i]>cap){
            days+=1;
            load=w[i];
        }
        else{
            load+=w[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& w, int days) {
        int low =*max_element(w.begin(),w.end());
        int high =accumulate(w.begin(),w.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int noOfDays=nod(w,mid);
            if(noOfDays<=days){
                high=mid-1;
            }
            else 
            low=mid+1;
        }
        return low;
    }
};