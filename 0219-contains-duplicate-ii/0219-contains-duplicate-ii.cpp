class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
            if(i-mp[nums[i]]<=k){
                return true;
            }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};
/*
another optimal 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end())
                return true;

            s.insert(nums[i]);

            if (i >= k)
                s.erase(nums[i - k]);
        }

        return false;
    }
};*/