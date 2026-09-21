class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>result(k,0);
        vector<long long>prevrem(k,0);
        for(int i=0;i<n;i++){
            vector<long long >curr(k,0);
            int currentelementrem=nums[i]%k;
            curr[currentelementrem]++;

            for(int oldrem=0;oldrem<=k-1;oldrem++){
                int newrem=((long long)oldrem*nums[i]%k)%k;
                curr[newrem]+=prevrem[oldrem];
            }
            prevrem=std::move(curr);
            for(int x=0;x<k;x++){
                result[x]+=prevrem[x];
            }

        }
        return result;
    }
};