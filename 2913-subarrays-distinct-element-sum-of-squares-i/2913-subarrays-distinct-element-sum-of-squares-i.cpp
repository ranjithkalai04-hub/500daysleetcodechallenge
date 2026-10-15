class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        set<int>s;
        int n=nums.size();

        for(int i=0; i<n; i++){
            ans+=1;
        }
        for(int left=0; left<n-1; left++){
            s.clear();
            for(int right=left+1; right<n; right++){
                s.insert(nums.begin()+left, nums.begin()+right+1);
                int size=s.size();
                ans+=(size*size);
            }
        }
        
        
        return ans;
        
    }
};