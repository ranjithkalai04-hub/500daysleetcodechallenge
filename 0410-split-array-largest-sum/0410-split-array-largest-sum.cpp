class Solution {
public:
int cof(vector<int>& nums, int mid){
    int inik=1;
    long long soArrE=0;
    for(int i=0;i<nums.size();i++){
        if(soArrE+nums[i]>mid)
        {
            inik++;
            soArrE=nums[i];
        }
        else{
            soArrE+=nums[i];
        }
    }
    return inik;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high =accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int countof=cof(nums,mid);
            if(countof>k){
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};