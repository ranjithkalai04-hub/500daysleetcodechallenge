class Solution {
public:
long long totalhr(vector<int>& piles, int mid)
{
    long long total=0;
    for(int i=0;i<piles.size();i++)
    {
         total+=ceil((double)piles[i]/mid);
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high=*max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid =(low+high)/2;
            long long totalhrs=totalhr(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};